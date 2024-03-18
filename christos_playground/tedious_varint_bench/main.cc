#include"dummyInitializations.h"
#include"iaa_comp.h"
#include"dummy.pb.h"
#include<fstream>

#define BUFFER_SIZE 1024
#define WARMUP_NUM_ITER 100
#define NUM_ITER 10000

struct statGatherer {
	double 	serTime;
	double 	deserTime;
	double 	compTime;
	double 	decompTime;
	double	serRatio;
	double	compRatio;

	void printStats() {
		std::cout << "LATENCIES:" << std::endl;
		std::cout << "Serialization: " << serTime << " nanoseconds" << std::endl;
		std::cout << "Deserialization: " << deserTime << " nanoseconds" << std::endl;
		std::cout << "Compression: " << compTime << " nanoseconds" << std::endl;
		std::cout << "Decompression: " << decompTime << " nanoseconds" << std::endl;
		std::cout << "COMPRESSION RATIOS: " << std::endl;
		std::cout << "Protobuf: " << serRatio << std::endl;
		std::cout << "IAA: " << compRatio << std::endl;
	}

	void dumpCsv(std::ofstream* fileStream) {
		if (fileStream == NULL)
			std::cout << serTime << "," << deserTime << "," << compTime << "," << decompTime << "," << serRatio << "," << compRatio << std::endl;
		else
			*fileStream << serTime << "," << deserTime << "," << compTime << "," << decompTime << "," << serRatio << "," << compRatio << std::endl;
	}
};

statGatherer smallVarintTest(int mode) {
	statGatherer stats;

	smallVarintDummy tmpStruct;
	initializeSmallDummy(&tmpStruct, mode);
	uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&tmpStruct);
	int initial_value_at_id_50 = tmpStruct.id50();

	/*****************************SERIALIZATION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	std::string serialized[NUM_ITER];

	// warmup proto serialization
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		tmpStruct.SerializeToString(&serialized[i]);
	}

    auto serStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		tmpStruct.SerializeToString(&serialized[i]);
	}

    auto serEndTime = std::chrono::high_resolution_clock::now();
  	auto serDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(serEndTime - serStartTime);

	stats.serTime  = ((float) serDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);
	stats.serRatio = ((float) sizeof(tmpStruct)) / serialized[0].size();
	/*
  	std::cout << "Serialization took " << serDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "SERIALIZATION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Compression Ratio, Latency" << std::endl;
	std::cout << sizeof(tmpStruct) << ", " << serialized[0].size() << ", " << ((float) sizeof(tmpStruct)) / serialized[0].size() << ", " << serDuration.count() / NUM_ITER << std::endl;
	*/

	/*****************************DESERIALIZATION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	smallVarintDummy testDummys[NUM_ITER];

	// warmup proto deserialization
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		testDummys[i].ParseFromString(serialized[i]);
	}

    auto deserStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		testDummys[i].ParseFromString(serialized[i]);
	}

    auto deserEndTime = std::chrono::high_resolution_clock::now();
  	auto deserDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(deserEndTime - deserStartTime);

	stats.deserTime  = ((float) deserDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);

	/*
  	std::cout << "Deserialization took " << deserDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "DESERIALIZATION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Latency" << std::endl;
	std::cout << serialized[0].size() << ", " << sizeof(testDummys[0]) << ", " << deserDuration.count() / NUM_ITER << std::endl;
	*/

	/*****************************COMPRESSION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	uint8_t compressed[NUM_ITER][BUFFER_SIZE];
	uint32_t comprOutputSize[NUM_ITER];

	// warmup IAA icache
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		compress_with_IAA(ogByteStream, sizeof(tmpStruct), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	}

    auto compStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		compress_with_IAA(ogByteStream, sizeof(tmpStruct), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	}

    auto compEndTime = std::chrono::high_resolution_clock::now();
  	auto compDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(compEndTime - compStartTime);

	stats.compTime  = ((float) compDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);
	stats.compRatio = ((float) sizeof(tmpStruct)) / comprOutputSize[0];

	/*
  	std::cout << "Compression took " << compDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "COMPRESSION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Compression Ratio, Latency" << std::endl;
	std::cout << sizeof(tmpStruct) << ", " << comprOutputSize[0] << ", " << ((float) sizeof(tmpStruct)) / comprOutputSize[0] << ", " << compDuration.count() / NUM_ITER << std::endl;
	*/
    
	/*****************************DECOMPRESSION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	uint8_t decompressed[NUM_ITER][BUFFER_SIZE];
	uint32_t decomprOutputSize[NUM_ITER];

	// warmup IAA icache
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
	}

    auto decompStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
	}

    auto decompEndTime = std::chrono::high_resolution_clock::now();
  	auto decompDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(decompEndTime - decompStartTime);

	stats.decompTime  = ((float) decompDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);

	/*
  	std::cout << "Decompression took " << decompDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "DECOMPRESSION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Latency" << std::endl;
	std::cout << comprOutputSize[0] << ", " << decomprOutputSize[0] << ", " << decompDuration.count() / NUM_ITER << std::endl;
	*/
	
	// validation
	uint32_t structSize = sizeof(tmpStruct);
	for (uint32_t i = 0; i < NUM_ITER; i++) {
		assert(decomprOutputSize[i] == structSize);
	}
	for (uint32_t i = 0; i < structSize; i++) {
		assert(ogByteStream[i] == decompressed[0][i]);
	}

	smallVarintDummy* new_tmp = reinterpret_cast<smallVarintDummy*>(decompressed[0]);
	assert(initial_value_at_id_50 == new_tmp->id50());

	return stats;
}

statGatherer biggerVarintTest(int mode) {
	statGatherer stats;

	biggerVarintDummy tmpStruct;
	initializeBiggerDummy(&tmpStruct, mode);
	uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&tmpStruct);
	int initial_value_at_id_50 = tmpStruct.id50();

	/*****************************SERIALIZATION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	std::string serialized[NUM_ITER];

	// warmup proto serialization
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		tmpStruct.SerializeToString(&serialized[i]);
	}

    auto serStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		tmpStruct.SerializeToString(&serialized[i]);
	}

    auto serEndTime = std::chrono::high_resolution_clock::now();
  	auto serDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(serEndTime - serStartTime);

	stats.serTime  = ((float) serDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);
	stats.serRatio = ((float) sizeof(tmpStruct)) / serialized[0].size();
	/*
  	std::cout << "Serialization took " << serDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "SERIALIZATION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Compression Ratio, Latency" << std::endl;
	std::cout << sizeof(tmpStruct) << ", " << serialized[0].size() << ", " << ((float) sizeof(tmpStruct)) / serialized[0].size() << ", " << serDuration.count() / NUM_ITER << std::endl;
	*/

	/*****************************DESERIALIZATION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	biggerVarintDummy testDummys[NUM_ITER];

	// warmup proto deserialization
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		testDummys[i].ParseFromString(serialized[i]);
	}

    auto deserStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		testDummys[i].ParseFromString(serialized[i]);
	}

    auto deserEndTime = std::chrono::high_resolution_clock::now();
  	auto deserDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(deserEndTime - deserStartTime);

	stats.deserTime  = ((float) deserDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);

	/*
  	std::cout << "Deserialization took " << deserDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "DESERIALIZATION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Latency" << std::endl;
	std::cout << serialized[0].size() << ", " << sizeof(testDummys[0]) << ", " << deserDuration.count() / NUM_ITER << std::endl;
	*/

	/*****************************COMPRESSION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	uint8_t compressed[NUM_ITER][BUFFER_SIZE];
	uint32_t comprOutputSize[NUM_ITER];

	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		compress_with_IAA(ogByteStream, sizeof(tmpStruct), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	}

    auto compStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		compress_with_IAA(ogByteStream, sizeof(tmpStruct), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	}

    auto compEndTime = std::chrono::high_resolution_clock::now();
  	auto compDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(compEndTime - compStartTime);

	stats.compTime  = ((float) compDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);
	stats.compRatio = ((float) sizeof(tmpStruct)) / comprOutputSize[0];

	/*
  	std::cout << "Compression took " << compDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "COMPRESSION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Compression Ratio, Latency" << std::endl;
	std::cout << sizeof(tmpStruct) << ", " << comprOutputSize[0] << ", " << ((float) sizeof(tmpStruct)) / comprOutputSize[0] << ", " << compDuration.count() / NUM_ITER << std::endl;
	*/
    
	/*****************************DECOMPRESSION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	uint8_t decompressed[NUM_ITER][BUFFER_SIZE];
	uint32_t decomprOutputSize[NUM_ITER];

	// warmup IAA icache
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
	}

    auto decompStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
	}

    auto decompEndTime = std::chrono::high_resolution_clock::now();
  	auto decompDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(decompEndTime - decompStartTime);

	stats.decompTime  = ((float) decompDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);

	/*
  	std::cout << "Decompression took " << decompDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "DECOMPRESSION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Latency" << std::endl;
	std::cout << comprOutputSize[0] << ", " << decomprOutputSize[0] << ", " << decompDuration.count() / NUM_ITER << std::endl;
	*/
	
	// validation
	uint32_t structSize = sizeof(tmpStruct);
	for (uint32_t i = 0; i < NUM_ITER; i++) {
		assert(decomprOutputSize[i] == structSize);
	}
	for (uint32_t i = 0; i < structSize; i++) {
		assert(ogByteStream[i] == decompressed[0][i]);
	}

	biggerVarintDummy* new_tmp = reinterpret_cast<biggerVarintDummy*>(decompressed[0]);
	assert(initial_value_at_id_50 == new_tmp->id50());

	return stats;
}

statGatherer evenBiggerVarintTest(int mode) {
	statGatherer stats;

	evenBiggerVarintDummy tmpStruct;
	initializeEvenBiggerDummy(&tmpStruct, mode);
	uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&tmpStruct);
	int initial_value_at_id_50 = tmpStruct.id50();

	/*****************************SERIALIZATION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	std::string serialized[NUM_ITER];

	// warmup proto deserialization
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		tmpStruct.SerializeToString(&serialized[i]);
	}

    auto serStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		tmpStruct.SerializeToString(&serialized[i]);
	}

    auto serEndTime = std::chrono::high_resolution_clock::now();
  	auto serDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(serEndTime - serStartTime);

	stats.serTime  = ((float) serDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);
	stats.serRatio = ((float) sizeof(tmpStruct)) / serialized[0].size();
	/*
  	std::cout << "Serialization took " << serDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "SERIALIZATION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Compression Ratio, Latency" << std::endl;
	std::cout << sizeof(tmpStruct) << ", " << serialized[0].size() << ", " << ((float) sizeof(tmpStruct)) / serialized[0].size() << ", " << serDuration.count() / NUM_ITER << std::endl;
	*/

	/*****************************DESERIALIZATION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	evenBiggerVarintDummy testDummys[NUM_ITER];

	// warmup proto deserialization
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		testDummys[i].ParseFromString(serialized[i]);
	}


    auto deserStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		testDummys[i].ParseFromString(serialized[i]);
	}

    auto deserEndTime = std::chrono::high_resolution_clock::now();
  	auto deserDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(deserEndTime - deserStartTime);

	stats.deserTime  = ((float) deserDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);

	/*
  	std::cout << "Deserialization took " << deserDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "DESERIALIZATION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Latency" << std::endl;
	std::cout << serialized[0].size() << ", " << sizeof(testDummys[0]) << ", " << deserDuration.count() / NUM_ITER << std::endl;
	*/

	/*****************************COMPRESSION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	uint8_t compressed[NUM_ITER][BUFFER_SIZE];
	uint32_t comprOutputSize[NUM_ITER];

	// warmup IAA icache
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		compress_with_IAA(ogByteStream, sizeof(tmpStruct), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	}

    auto compStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		compress_with_IAA(ogByteStream, sizeof(tmpStruct), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	}

    auto compEndTime = std::chrono::high_resolution_clock::now();
  	auto compDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(compEndTime - compStartTime);

	stats.compTime  = ((float) compDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);
	stats.compRatio = ((float) sizeof(tmpStruct)) / comprOutputSize[0];

	/*
  	std::cout << "Compression took " << compDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "COMPRESSION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Compression Ratio, Latency" << std::endl;
	std::cout << sizeof(tmpStruct) << ", " << comprOutputSize[0] << ", " << ((float) sizeof(tmpStruct)) / comprOutputSize[0] << ", " << compDuration.count() / NUM_ITER << std::endl;
	*/
    
	/*****************************DECOMPRESSION BENCH*****************************/
	//std::cout << "**********************************************************" << std::endl;
	uint8_t decompressed[NUM_ITER][BUFFER_SIZE];
	uint32_t decomprOutputSize[NUM_ITER];

	// warmup IAA icache
	for (uint32_t i = 0; i < WARMUP_NUM_ITER; i++) {
		decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
	}

    auto decompStartTime = std::chrono::high_resolution_clock::now();

	for (uint32_t i = WARMUP_NUM_ITER; i < NUM_ITER; i++) {
		decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
	}

    auto decompEndTime = std::chrono::high_resolution_clock::now();
  	auto decompDuration = std::chrono::duration_cast<std::chrono::nanoseconds>(decompEndTime - decompStartTime);

	stats.decompTime  = ((float) decompDuration.count()) / (NUM_ITER - WARMUP_NUM_ITER);

	/*
  	std::cout << "Decompression took " << decompDuration.count() / NUM_ITER << " nanoseconds" << std::endl;
	std::cout << "DECOMPRESSION STATS" << std::endl;
	std::cout << "Input Size, Output Size, Latency" << std::endl;
	std::cout << comprOutputSize[0] << ", " << decomprOutputSize[0] << ", " << decompDuration.count() / NUM_ITER << std::endl;
	*/
	
	// validation
	uint32_t structSize = sizeof(tmpStruct);
	for (uint32_t i = 0; i < NUM_ITER; i++) {
		assert(decomprOutputSize[i] == structSize);
	}
	for (uint32_t i = 0; i < structSize; i++) {
		assert(ogByteStream[i] == decompressed[0][i]);
	}

	evenBiggerVarintDummy* new_tmp = reinterpret_cast<evenBiggerVarintDummy*>(decompressed[0]);
	assert(initial_value_at_id_50 == new_tmp->id50());

	return stats;
}

int main (int argc, char* argv[]) {
	// Initialize IAA jobs for compression
	iaa_init_jobs(qpl_path_hardware);

	statGatherer stats[18];
	std::string modes[] = {"1 byte", "2 bytes", "3 bytes", "4 bytes", "random", "uni"};

	for (uint32_t i = 0; i < 18; i++) {
		if (i < 6) {
			stats[i] = smallVarintTest(i+1);
		}
		else if (i < 12) {
			stats[i] = biggerVarintTest(i%6 + 1);
		}
		else {
			stats[i] = evenBiggerVarintTest(i%6 + 1);
		}
	}

	std::ofstream outputFile("results.csv");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

	outputFile << "Varints,Mode,SerTime,DeserTime,CompTime,DecompTime,ProtoRatio,CompRatio" << std::endl;
	for (uint32_t i = 0; i < 18; i++) {
		if (i < 6)
			outputFile << "50 varints," << modes[i] << ",";
		else if (i < 12)
			outputFile << "100 varints," << modes[i%6] << ",";
		else
			outputFile << "200 varints," << modes[i%6] << ",";

		stats[i].dumpCsv(&outputFile);
	}

	iaa_fini_jobs();
	return 0;
}
