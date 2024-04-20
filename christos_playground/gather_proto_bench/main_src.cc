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
		(&m)->set_f1(13039 + (i * 1) % 8);
		(&m)->set_f2(22695 + (i * 1) % 8);
		(&m)->set_f3(54 + (i * 1) % 8);
		(&m)->set_f4(28723 + (i * 1) % 8);
		(&m)->set_f5(168 + (i * 1) % 8);
		(&m)->set_f6(2667075 + (i * 1) % 8);
		(&m)->set_f7(3579906261 + (i * 1) % 8);
		(&m)->set_f8(29 + (i * 1) % 8);
		(&m)->set_f9(52137 + (i * 1) % 8);
		(&m)->set_f10(167 + (i * 1) % 8);
		(&m)->set_f11(3112903625 + (i * 1) % 8);
		(&m)->set_f12(2985025 + (i * 1) % 8);
		(&m)->set_f13(664205242 + (i * 1) % 8);
		(&m)->set_f14(1320061231 + (i * 1) % 8);
		(&m)->set_f15(16244055 + (i * 1) % 8);
		(&m)->set_f16(2704185881 + (i * 1) % 8);
		(&m)->set_f17(7716300 + (i * 1) % 8);
		(&m)->set_f18(1018519388 + (i * 1) % 8);
		(&m)->set_f19(29531 + (i * 1) % 8);
		(&m)->set_f20(21020711 + (i * 1) % 8);
		(&m)->mutable_f21()->set_f1(506 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f2(39199 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f3(22166 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f4(2998419128 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f5(565680272 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f6(90174 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f7(167 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f8(61296 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f9(14421 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f10(7 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f11(135 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f12(7635 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f13(183 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f14(14521317 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f15(37052 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f16(16449466 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f17(91 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f18(53604 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f19(11922614 + (i * 2) % 8);
		(&m)->mutable_f21()->set_f20(381676240 + (i * 2) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f1(826451418 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f2(2939097801 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f3(12432578 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f4(1137240 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f5(25688 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f6(12187982 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f7(1164832674 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f8(24315 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f9(24057 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f10(5618927 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f11(3504338975 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f12(14876150 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f13(51757 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f14(2211653136 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f15(4942074 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f16(10820942 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f17(60664 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f18(7370059 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f19(39 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->set_f20(12936713 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f1(34512 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f2(2790096992 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f3(13144847 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f4(2008316 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f5(40 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f6(25941 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f7(216 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f8(56852 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f9(149 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f10(116 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f11(60062 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f12(4175155989 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f13(7512908 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f14(2134439981 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f15(146 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f16(7944362 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f17(2427424901 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f18(59948 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f19(4246739094 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f21()->set_f20(7843462 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f1(8117132 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f2(15974 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f3(7169661 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f4(12437464 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f5(1873937897 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f6(11344581 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f7(32647 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f8(12296 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f9(1223071 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f10(238 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f11(18 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f12(12185154 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f13(58588 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f14(10727 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f15(3909710669 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f16(2955664 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f17(663329645 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f18(13028410 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f19(28883 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f21()->mutable_f22()->set_f20(63973 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f1(1800683 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f2(7209075 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f3(909657220 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f4(5589683 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f5(10343252 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f6(6642 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f7(48575 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f8(51550 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f9(19772 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f10(282141113 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f11(17443 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f12(1343881144 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f13(68 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f14(130 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f15(49559 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f16(4268328881 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f17(238 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f18(53222 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f19(1524306 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->set_f20(43413 + (i * 3) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f1(5014109 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f2(3400983579 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f3(655815 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f4(3515891606 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f5(4138134 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f6(34645 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f7(62547 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f8(45971 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f9(43467 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f10(28 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f11(888473572 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f12(16434605 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f13(19712 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f14(5741244 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f15(13317728 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f16(73 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f17(140 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f18(44971 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f19(96 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f21()->set_f20(18412 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f1(49659 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f2(89 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f3(19376 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f4(60 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f5(6541524 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f6(15400 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f7(13099101 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f8(10594 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f9(8498 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f10(48785 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f11(864025158 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f12(112 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f13(3927633645 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f14(26 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f15(31 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f16(3188493693 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f17(9247914 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f18(1717981235 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f19(15899580 + (i * 4) % 8);
		(&m)->mutable_f21()->mutable_f22()->mutable_f22()->set_f20(2517562746 + (i * 4) % 8);
		(&m)->mutable_f22()->set_f1(2827926104 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f2(2797323909 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f3(16147914 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f4(40 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f5(65192 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f6(3915470573 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f7(912455 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f8(1280984784 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f9(97 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f10(8308899 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f11(163 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f12(637698076 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f13(2646236070 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f14(8743068 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f15(2177460847 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f16(16064868 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f17(11334343 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f18(56 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f19(75 + (i * 2) % 8);
		(&m)->mutable_f22()->set_f20(61678 + (i * 2) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f1(218 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f2(182 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f3(442310398 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f4(3266180635 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f5(17443 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f6(591 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f7(48413 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f8(19 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f9(31407 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f10(64461 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f11(39642 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f12(177 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f13(3218138781 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f14(12573553 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f15(20711 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f16(15744001 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f17(1212571270 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f18(52129 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f19(2285548 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->set_f20(172 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f1(845976959 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f2(1567846060 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f3(28 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f4(5108578 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f5(32040 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f6(1670768399 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f7(537402 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f8(54974 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f9(3537698974 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f10(15984 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f11(234 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f12(218 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f13(16548098 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f14(277466582 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f15(695412968 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f16(2558065174 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f17(1228831492 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f18(1683548277 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f19(3477068702 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f21()->set_f20(721924874 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f1(13327847 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f2(3718405173 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f3(103 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f4(30032 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f5(1247722636 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f6(1857262681 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f7(1045604 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f8(59491 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f9(1651711087 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f10(11289268 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f11(13653821 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f12(11296369 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f13(217 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f14(58574 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f15(887 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f16(10308503 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f17(36398 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f18(1102144213 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f19(56148 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f21()->mutable_f22()->set_f20(40148 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f1(133341 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f2(239 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f3(50781 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f4(184 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f5(1394423195 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f6(7854583 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f7(27934 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f8(97494 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f9(34800 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f10(244 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f11(7269738 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f12(60489 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f13(15535582 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f14(252 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f15(72 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f16(16801 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f17(10070484 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f18(1125717339 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f19(44603 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->set_f20(10148648 + (i * 3) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f1(45946 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f2(1955164744 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f3(185 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f4(7896141 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f5(9868622 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f6(10684998 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f7(11975925 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f8(2883059503 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f9(1096644 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f10(135 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f11(12629312 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f12(11889180 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f13(41552 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f14(3573690 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f15(237 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f16(26928 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f17(2932122040 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f18(107 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f19(12209144 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f21()->set_f20(42114 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f1(2953806 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f2(242 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f3(12660529 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f4(0 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f5(28709 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f6(113 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f7(1862 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f8(24442 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f9(7485645 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f10(51511 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f11(1 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f12(3555898 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f13(2 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f14(136851423 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f15(154 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f16(4003605 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f17(139 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f18(30825 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f19(1684861407 + (i * 4) % 8);
		(&m)->mutable_f22()->mutable_f22()->mutable_f22()->set_f20(13758949 + (i * 4) % 8);

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
    std::cout << "Deserialization took = " << took_ns / (messages.size() - kNofWarmUpIterations) << " [ns]" << std::endl;

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
    std::cout << "Gather+Compressing took : " << took_ns / (kNofIterations - kNofWarmUpIterations) << " nanoseconds, ";

    std::cout << "Gathered size : " << out_size << " bytes, ";
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
