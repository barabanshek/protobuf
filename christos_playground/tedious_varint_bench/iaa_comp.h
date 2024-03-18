#include<iostream>
#include<cassert>
#include<memory>

#include "qpl/qpl.h"

static std::unique_ptr<uint8_t[]> init_qpl(qpl_path_t e_path) {
  // Job initialization.
  uint32_t job_size = 0;
  qpl_status status = qpl_get_job_size(e_path, &job_size);
  if (status != QPL_STS_OK) {
    std::cout << "An error acquired during job size getting." << std::endl;
    return std::unique_ptr<uint8_t[]>(nullptr);
  }

  std::unique_ptr<uint8_t[]> job_buffer;
  job_buffer = std::make_unique<uint8_t[]>(job_size);
  auto job = reinterpret_cast<qpl_job *>(job_buffer.get());
  status = qpl_init_job(e_path, job);
  if (status != QPL_STS_OK) {
    std::cout << "An error acquired during compression job initializing." << std::endl;
    return std::unique_ptr<uint8_t[]>(nullptr);
  }

  return std::move(job_buffer);
}

static int free_qpl(qpl_job *job) {
  qpl_status status = qpl_fini_job(job);
  if (status != QPL_STS_OK) {
    std::cout << "An error acquired during job finalization." << std::endl;
    return -1;
  }

  return 0;
}

std::unique_ptr<uint8_t[]> global_job_buffer;
qpl_job* job;

int iaa_init_jobs(qpl_path_t path) {
	global_job_buffer = init_qpl(path);
    if (global_job_buffer == nullptr) {
        std::cout << "Failed to init qpl." << std::endl;
        return -1;
    }
	job = reinterpret_cast<qpl_job *>(global_job_buffer.get());
	return 0;
}

int iaa_fini_jobs() {
    if (free_qpl(job)) {
        std::cout << "Failed to free resources." << std::endl;
        return -1;
    }
	return 0;
}

int compress_with_IAA(uint8_t* src, uint32_t srcSize, uint8_t* outBStream, uint32_t outBufferSize, uint32_t* actualOutSize) {
    // Create job for compressing the byte stream
    job->op             = qpl_op_compress;
    job->level          = qpl_default_level;
    job->next_in_ptr 	= src;
    job->available_in   = srcSize;
    job->next_out_ptr   = outBStream;
    job->available_out  = outBufferSize;
    //job->flags          = QPL_FLAG_FIRST | QPL_FLAG_LAST | QPL_FLAG_DYNAMIC_HUFFMAN | QPL_FLAG_OMIT_VERIFY;
    job->flags          = QPL_FLAG_FIRST | QPL_FLAG_LAST | QPL_FLAG_OMIT_VERIFY;

    qpl_status status = qpl_execute_job(job);
    if (status != QPL_STS_OK) {
        std::cout << "An error " << status << " acquired during compression." << std::endl;
        return -1;
    }

	*actualOutSize = job->total_out;
    return 0;
}

int decompress_with_IAA(uint8_t* src, uint32_t srcSize, uint8_t* outBStream, uint32_t outBufferSize, uint32_t* actualOutSize) {
    // Create job for decompressing the byte stream
    job->op 			= qpl_op_decompress;
    job->next_in_ptr 	= src;
    job->available_in   = srcSize;
    job->next_out_ptr   = outBStream;
    job->available_out  = outBufferSize;
    job->flags 			= QPL_FLAG_FIRST | QPL_FLAG_LAST; // | QPL_FLAG_CANNED_MODE;

    qpl_status status = qpl_execute_job(job);
    if (status != QPL_STS_OK) {
        std::cout << "An error " << status << " acquired during compression." << std::endl;
        return -1;
    }

	*actualOutSize = job->total_out;
    return 0;
}
