#include <google/protobuf/util/message_differencer.h>

#include"person.pb.h"
#include"scatter_gather.h"
#include"iaa_comp.h"

static constexpr size_t kNofIterations = 10000;
static constexpr size_t kNofWarmUpIterations = 100;

#define BUFFER_SIZE 4096

int main () {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compiled against.
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    // initialize iaa jobs
	iaa_init_jobs(qpl_path_hardware);
	//iaa_init_jobs(qpl_path_software);

    std::vector<M> messages;
    //messages.reserve(kNofIterations);
    std::vector<std::string> ser_outs;
    // IAA utility arrays
    uint8_t** compressed   = new uint8_t*[kNofIterations];
    uint8_t** decompressed = new uint8_t*[kNofIterations];
    for (size_t i = 0; i < kNofIterations; ++i) {
        compressed[i]   = new uint8_t[BUFFER_SIZE];
        decompressed[i] = new uint8_t[BUFFER_SIZE];
    }
    // arrays for keeping output size feedback from IAA
    uint32_t* comprOutputSize   = new uint32_t[kNofIterations];
    uint32_t* decomprOutputSize = new uint32_t[kNofIterations];

    for (size_t i = 0; i < kNofIterations; ++i) {
        M m;

        // <------------ SETTERS ------>
		(&m)->set_f1(12656152 + (i * 1) % 8);
		(&m)->set_f2(8774595 + (i * 1) % 8);
		(&m)->set_f3(139 + (i * 1) % 8);
		(&m)->set_f4(1781173164 + (i * 1) % 8);
		(&m)->set_f5(13 + (i * 1) % 8);
		(&m)->set_f6(1643065561 + (i * 1) % 8);
		(&m)->set_f7(2369147180 + (i * 1) % 8);
		(&m)->set_f8(1846361 + (i * 1) % 8);
		(&m)->set_f9(3602791957 + (i * 1) % 8);
		(&m)->set_f10(5628176 + (i * 1) % 8);
		(&m)->set_f11(238 + (i * 1) % 8);
		(&m)->set_f12(212 + (i * 1) % 8);
		(&m)->set_f13(131 + (i * 1) % 8);
		(&m)->set_f14(7870225 + (i * 1) % 8);
		(&m)->set_f15(65312 + (i * 1) % 8);
		(&m)->set_f16(113 + (i * 1) % 8);
		(&m)->set_f17(45812 + (i * 1) % 8);
		(&m)->set_f18(55027267 + (i * 1) % 8);
		(&m)->set_f19(193 + (i * 1) % 8);
		(&m)->set_f20(2522792075 + (i * 1) % 8);
		(&m)->mutable_f21()->set_f1(7245 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f2(2117929 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f3(3598287 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f4(4004014 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f5(3421349 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f6(3385179760 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f7(85 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f8(4965528 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f9(72 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f10(11286 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f11(2795290486 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f12(56178 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f13(13 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f14(116 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f15(9969570 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f16(61109 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f17(17 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f18(3213923431 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f19(481073499 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f20(15371322 + (i * 2) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f1(39089 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f2(63006 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f3(46220 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f4(16554795 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f5(88 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f6(1850280375 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f7(2766401669 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f8(18750 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f9(102 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f10(29091 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f11(3870949889 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f12(2419036 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f13(51596 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f14(1062277692 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f15(202 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f16(25583 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f17(6055 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f18(301662 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f19(37 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f20(68 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f1(111 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f2(47325 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f3(2079473273 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f4(176 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f5(31719 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f6(2145978278 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f7(762370965 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f8(3047903628 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f9(7147 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f10(2689096791 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f11(255 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f12(30536 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f13(9258 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f14(2144058108 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f15(156802413 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f16(160 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f17(34665 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f18(120 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f19(3359913193 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f20(2012808119 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f1(9689617 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f2(37001 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f3(118 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f4(3184911738 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f5(20759 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f6(190493992 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f7(56658 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f8(225 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f9(3146682219 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f10(156978626 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f11(3532958157 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f12(1324578809 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f13(13090335 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f14(6008 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f15(3305001847 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f16(35629 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f17(3 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f18(9091852 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f19(103 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f20(12323 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f1(20112 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f2(26917 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f3(4233873624 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f4(7289944 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f5(1311656695 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f6(10 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f7(3418550401 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f8(3042037249 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f9(807153563 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f10(3116615521 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f11(32 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f12(8543059 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f13(96 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f14(65 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f15(52777 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f16(1652356114 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f17(206 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f18(57 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f19(12474 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f20(1136917466 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f1(7586301 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f2(3933164617 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f3(35 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f4(2871712531 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f5(203 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f6(1589214188 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f7(6249150 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f8(1973739 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f9(78 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f10(225 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f11(57560 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f12(154 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f13(8599591 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f14(2774863 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f15(1701723790 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f16(3839887121 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f17(165 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f18(3193413987 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f19(91 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f20(8111071 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f1(24205 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f2(243 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f3(16728144 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f4(17136 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f5(27585 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f6(33562 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f7(24712 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f8(3596654875 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f9(22904 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f10(9392687 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f11(23104 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f12(1707984538 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f13(946377132 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f14(2169914 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f15(1642671 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f16(8159440 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f17(29809 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f18(6771266 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f19(1933998187 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f20(21758 + (i * 4) % 8);
		(&m)->mutable_f22()->set_f1(23042 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f2(57929845 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f3(4212542607 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f4(8883520 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f5(1426673781 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f6(22193 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f7(7520435 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f8(18 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f9(3161940600 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f10(121 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f11(14364943 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f12(6491446 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f13(5763002 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f14(101 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f15(61557 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f16(16130686 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f17(36 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f18(1429721070 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f19(18 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f20(7461680 + (i * 2) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f1(1426656 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f2(2488149 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f3(63875 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f4(44620 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f5(35611 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f6(16171651 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f7(3737 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f8(2716382 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f9(99095006 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f10(16834 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f11(886498586 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f12(130 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f13(7365438 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f14(1014526 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f15(70 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f16(13130731 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f17(173 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f18(166 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f19(242 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f20(814579624 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f1(1930539741 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f2(236 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f3(234 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f4(7599955 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f5(13732682 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f6(26 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f7(15530057 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f8(101 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f9(205 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f10(1536165731 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f11(191 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f12(115 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f13(668374179 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f14(92677804 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f15(26225 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f16(17748 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f17(5144902 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f18(5973 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f19(6906914 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f20(65 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f1(64408 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f2(4038172267 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f3(3523165968 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f4(2649405 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f5(32115 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f6(199 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f7(14478 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f8(672390998 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f9(250 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f10(19361 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f11(202 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f12(49 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f13(90 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f14(224 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f15(252 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f16(13790637 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f17(74 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f18(154 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f19(38 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f20(32906 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f1(40031 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f2(2937516112 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f3(2585229356 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f4(6 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f5(144 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f6(14114202 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f7(50657 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f8(1 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f9(136 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f10(160 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f11(12659237 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f12(16140105 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f13(65192 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f14(29353 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f15(2916600291 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f16(230 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f17(21 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f18(177 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f19(1276101326 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f20(3 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f1(182 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f2(9398400 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f3(973 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f4(10074593 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f5(730 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f6(1187195540 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f7(87 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f8(6209288 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f9(29897 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f10(153501726 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f11(100 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f12(50920 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f13(3295108639 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f14(2739022016 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f15(53090 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f16(243 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f17(39772 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f18(150 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f19(11412594 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f20(3380683940 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f1(25631 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f2(50851 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f3(2997154178 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f4(545525445 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f5(23969 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f6(1957396154 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f7(341980009 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f8(61403 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f9(199 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f10(5776188 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f11(117 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f12(1238450919 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f13(1902178 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f14(1725600 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f15(97 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f16(1820354574 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f17(44397 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f18(245 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f19(742991959 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f20(3212868625 + (i * 4) % 8);

        //messages[i] = m;
        messages.push_back(m);
        ser_outs.push_back("");
    }

    // Gather schemas
    std::vector<ScatterGather::Schema> schemas;
    for (size_t i = 0; i < kNofIterations; ++i) {
        ScatterGather::Schema schema;

        // <------------ SCHEMA ------>
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])), sizeof(*((&messages[i])))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f21()), sizeof(*((&messages[i])->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f21()->mutable_f21()), sizeof(*((&messages[i])->mutable_f21()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f21()->mutable_f21()->mutable_f21()), sizeof(*((&messages[i])->mutable_f21()->mutable_f21()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f21()->mutable_f21()->mutable_f22()), sizeof(*((&messages[i])->mutable_f21()->mutable_f21()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f21()->mutable_f22()), sizeof(*((&messages[i])->mutable_f21()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f21()->mutable_f22()->mutable_f21()), sizeof(*((&messages[i])->mutable_f21()->mutable_f22()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f21()->mutable_f22()->mutable_f22()), sizeof(*((&messages[i])->mutable_f21()->mutable_f22()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f22()), sizeof(*((&messages[i])->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f22()->mutable_f21()), sizeof(*((&messages[i])->mutable_f22()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f22()->mutable_f21()->mutable_f21()), sizeof(*((&messages[i])->mutable_f22()->mutable_f21()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f22()->mutable_f21()->mutable_f22()), sizeof(*((&messages[i])->mutable_f22()->mutable_f21()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f22()->mutable_f22()), sizeof(*((&messages[i])->mutable_f22()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f22()->mutable_f22()->mutable_f21()), sizeof(*((&messages[i])->mutable_f22()->mutable_f22()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&messages[i])->mutable_f22()->mutable_f22()->mutable_f22()), sizeof(*((&messages[i])->mutable_f22()->mutable_f22()->mutable_f22()))));

        schemas.push_back(schema);
    }

    //
    // Benchmark serialize.
    //
    // Warm-up.
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (!messages[i].SerializeToString(&ser_outs[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
        if (!messages[i].SerializeToString(&ser_outs[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Serialization took = " << took_ns / (kNofIterations - kNofWarmUpIterations) << " [ns], size = " << ser_outs[0].size() << " Bytes" << std::endl;

    //
    // Benchmark deserialize.
    //
    std::vector<M> deser_messages_out;
    for (size_t i = 0; i < messages.size(); ++i) deser_messages_out.push_back(M());

    // Warm-up.
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (!deser_messages_out[i].ParseFromString(ser_outs[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }

    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
        if (!deser_messages_out[i].ParseFromString(ser_outs[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Deserialization took = " << took_ns / (messages.size() - kNofWarmUpIterations) << " [ns], size = " << ser_outs[0].size() << " Bytes" << std::endl;

    // GATHER + COMPRESSION

    ScatterGather scagatherer;
    size_t out_size = 0;
    std::vector<std::vector<uint8_t>> gather_outs(kNofIterations, std::vector<uint8_t>(BUFFER_SIZE, 0));

    // warmup for both
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (scagatherer.GatherWithMemCpy(schemas[i], gather_outs[i].data(), &out_size) ) {
            std::cerr << "Failed to gather" << std::endl;
            return -1;
        }
        if (compress_with_IAA(gather_outs[i].data(), out_size, compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }

    // warmup the output buffers
    /*
    long long make_it_hot = 0;
    for (size_t i = 0; i < kNofIterations; ++i) {
        for (size_t j = 0; j < BUFFER_SIZE; ++j) {
            make_it_hot += compressed[i][j];
        }
    }
    assert(make_it_hot != 0);
    */

    // gather
    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < kNofIterations; ++i) {
        if (scagatherer.GatherWithMemCpy(schemas[i], gather_outs[i].data(), &out_size) ) {
            std::cerr << "Failed to gather" << std::endl;
            return -1;
        }
    /*
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Gathering took : " << took_ns / (kNofIterations - kNofWarmUpIterations) << " nanoseconds" << std::endl;

    // compress
    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < kNofIterations; ++i) {
    */
        if (compress_with_IAA(gather_outs[i].data(), out_size, compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Gather+Compressing took : " << took_ns / (kNofIterations - kNofWarmUpIterations) << " nanoseconds" << std::endl;

    std::cout << "Gathered size : " << out_size << " bytes" << std::endl;
    std::cout << "Compressed size : " << comprOutputSize[0] << " bytes" << std::endl;

    // DECOMPRESSION + SCATTER

    // create scatter schemas and output messages
    // output messages after decompression and scatter
    std::vector<M> out_messages;
    //out_messages.reserve(kNofIterations);
    // Scatter schemas
    std::vector<ScatterGather::Schema> scatter_schemas;
    for (size_t i = 0; i < kNofIterations; ++i) {
        M m;
        out_messages.push_back(m);
    }

    for (size_t i = 0; i < kNofIterations; ++i) {
        ScatterGather::Schema schema;

        // <------------ SCATTER SCHEMA ------>
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])), sizeof(*((&out_messages[i])))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f21()), sizeof(*((&out_messages[i])->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f21()->mutable_f21()), sizeof(*((&out_messages[i])->mutable_f21()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f21()->mutable_f21()->mutable_f21()), sizeof(*((&out_messages[i])->mutable_f21()->mutable_f21()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f21()->mutable_f21()->mutable_f22()), sizeof(*((&out_messages[i])->mutable_f21()->mutable_f21()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f21()->mutable_f22()), sizeof(*((&out_messages[i])->mutable_f21()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f21()->mutable_f22()->mutable_f21()), sizeof(*((&out_messages[i])->mutable_f21()->mutable_f22()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f21()->mutable_f22()->mutable_f22()), sizeof(*((&out_messages[i])->mutable_f21()->mutable_f22()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f22()), sizeof(*((&out_messages[i])->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f22()->mutable_f21()), sizeof(*((&out_messages[i])->mutable_f22()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f22()->mutable_f21()->mutable_f21()), sizeof(*((&out_messages[i])->mutable_f22()->mutable_f21()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f22()->mutable_f21()->mutable_f22()), sizeof(*((&out_messages[i])->mutable_f22()->mutable_f21()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f22()->mutable_f22()), sizeof(*((&out_messages[i])->mutable_f22()->mutable_f22()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f22()->mutable_f22()->mutable_f21()), sizeof(*((&out_messages[i])->mutable_f22()->mutable_f22()->mutable_f21()))));
		schema.push_back(std::make_tuple(reinterpret_cast<uint8_t*>((&out_messages[i])->mutable_f22()->mutable_f22()->mutable_f22()), sizeof(*((&out_messages[i])->mutable_f22()->mutable_f22()->mutable_f22()))));

        scatter_schemas.push_back(schema);
    }

    // warmup decompress+scatter
    for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
        if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
        if (scagatherer.ScatterWithMemCpy(decompressed[i], scatter_schemas[i])) {
            std::cout << "Failed to scatter" << std::endl;
            return -1;
        }
    }

    begin = std::chrono::steady_clock::now();
    for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
        if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
            std::cerr << "Benchmark error." << std::endl;
            return -1;
        }
        if (scagatherer.ScatterWithMemCpy(decompressed[i], scatter_schemas[i])) {
            std::cout << "Failed to scatter" << std::endl;
            return -1;
        }
    }
    end = std::chrono::steady_clock::now();
    took_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    std::cout << "Decompression+Scatter took = " << took_ns / (kNofIterations - kNofWarmUpIterations) << " [ns], size = " << decomprOutputSize[0] << " Bytes" << std::endl;

    // Verify correctness
    /*
    */
    bool all_correct = true;

    for (size_t i = 0; i < kNofIterations && all_correct; ++i) {
        all_correct = google::protobuf::util::MessageDifferencer::Equals(messages[i], out_messages[i]);
    }

    std::cout << (all_correct ? "ALL CORRECT" : "ERROR: DATA MISSMATCH") << std::endl;

    /*
    */
    // Optional:  Delete all global objects allocated by libprotobuf.
    //google::protobuf::ShutdownProtobufLibrary();

    for (size_t i = 0; i < kNofIterations; ++i) {
        delete[] compressed[i];
        delete[] decompressed[i];
    }
    delete[] compressed;
    delete[] decompressed;

    // free existing iaa jobs
	iaa_fini_jobs();

    return 0;
}
