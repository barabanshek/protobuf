#include <google/protobuf/util/message_differencer.h>

#include <fstream>
#include <iostream>
#include <string>

#include "iaa_comp.h"
#include "person.pb.h"

#define BUFFER_SIZE 4096

static constexpr size_t kNofIterations = 10000;
static constexpr size_t kNofWarmUpIterations = 100;

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  // initialize iaa jobs
	iaa_init_jobs(qpl_path_software);

  std::vector<M> messages;
  // arrays for keeping the buffering the intermediate outputs of IAA
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
(&m)->set_f1(226 + (i * 1) % 8);
(&m)->set_f2(13970 + (i * 1) % 8);
(&m)->set_f3(12802583 + (i * 1) % 8);
(&m)->set_f4(874530773 + (i * 1) % 8);
(&m)->set_f5(241 + (i * 1) % 8);
(&m)->set_f6(2454672024 + (i * 1) % 8);
(&m)->set_f7(754630734 + (i * 1) % 8);
(&m)->set_f8(250269292 + (i * 1) % 8);
(&m)->set_f9(2315 + (i * 1) % 8);
(&m)->set_f10(27942 + (i * 1) % 8);
(&m)->set_f11(2739788333 + (i * 1) % 8);
(&m)->set_f12(20132 + (i * 1) % 8);
(&m)->set_f13(29 + (i * 1) % 8);
(&m)->set_f14(158 + (i * 1) % 8);
(&m)->set_f15(1984619411 + (i * 1) % 8);
(&m)->set_f16(30 + (i * 1) % 8);
(&m)->set_f17(3895259317 + (i * 1) % 8);
(&m)->set_f18(17773 + (i * 1) % 8);
(&m)->set_f19(1010120579 + (i * 1) % 8);
(&m)->set_f20(5843836 + (i * 1) % 8);
(&m)->set_f21(244 + (i * 1) % 8);
(&m)->set_f22(7143 + (i * 1) % 8);
(&m)->set_f23(22066 + (i * 1) % 8);
(&m)->set_f24(10541677 + (i * 1) % 8);
(&m)->set_f25(12154 + (i * 1) % 8);
(&m)->set_f26(14368 + (i * 1) % 8);
(&m)->set_f27(59 + (i * 1) % 8);
(&m)->set_f28(12819119 + (i * 1) % 8);
(&m)->set_f29(5085570 + (i * 1) % 8);
(&m)->set_f30(16276603 + (i * 1) % 8);
(&m)->set_f31(209 + (i * 1) % 8);
(&m)->set_f32(863049052 + (i * 1) % 8);
(&m)->set_f33(138 + (i * 1) % 8);
(&m)->set_f34(62052 + (i * 1) % 8);
(&m)->set_f35(243 + (i * 1) % 8);
(&m)->set_f36(14656999 + (i * 1) % 8);
(&m)->set_f37(4261588 + (i * 1) % 8);
(&m)->set_f38(198 + (i * 1) % 8);
(&m)->set_f39(241 + (i * 1) % 8);
(&m)->set_f40(4037130801 + (i * 1) % 8);
(&m)->set_f41(4169 + (i * 1) % 8);
(&m)->set_f42(2512667387 + (i * 1) % 8);
(&m)->set_f43(65170 + (i * 1) % 8);
(&m)->set_f44(159922 + (i * 1) % 8);
(&m)->set_f45(19833 + (i * 1) % 8);
(&m)->set_f46(1328145691 + (i * 1) % 8);
(&m)->set_f47(123 + (i * 1) % 8);
(&m)->set_f48(181 + (i * 1) % 8);
(&m)->set_f49(4195450 + (i * 1) % 8);
(&m)->set_f50(2185349757 + (i * 1) % 8);
(&m)->set_f51(92 + (i * 1) % 8);
(&m)->set_f52(120 + (i * 1) % 8);
(&m)->set_f53(14890160 + (i * 1) % 8);
(&m)->set_f54(1367694 + (i * 1) % 8);
(&m)->set_f55(4623904 + (i * 1) % 8);
(&m)->set_f56(55464 + (i * 1) % 8);
(&m)->set_f57(103 + (i * 1) % 8);
(&m)->set_f58(9407400 + (i * 1) % 8);
(&m)->set_f59(3684889674 + (i * 1) % 8);
(&m)->set_f60(88 + (i * 1) % 8);
(&m)->set_f61(4141840552 + (i * 1) % 8);
(&m)->set_f62(11373198 + (i * 1) % 8);
(&m)->set_f63(522 + (i * 1) % 8);
(&m)->set_f64(45951 + (i * 1) % 8);
(&m)->set_f65(233 + (i * 1) % 8);
(&m)->set_f66(6047412 + (i * 1) % 8);
(&m)->set_f67(40768 + (i * 1) % 8);
(&m)->set_f68(33 + (i * 1) % 8);
(&m)->set_f69(163 + (i * 1) % 8);
(&m)->set_f70(637429586 + (i * 1) % 8);
(&m)->set_f71(129 + (i * 1) % 8);
(&m)->set_f72(16759501 + (i * 1) % 8);
(&m)->set_f73(31 + (i * 1) % 8);
(&m)->set_f74(72 + (i * 1) % 8);
(&m)->set_f75(5601 + (i * 1) % 8);
(&m)->set_f76(242 + (i * 1) % 8);
(&m)->set_f77(3814814443 + (i * 1) % 8);
(&m)->set_f78(49377 + (i * 1) % 8);
(&m)->set_f79(2117303837 + (i * 1) % 8);
(&m)->set_f80(11594 + (i * 1) % 8);
(&m)->set_f81(32 + (i * 1) % 8);
(&m)->set_f82(2847497 + (i * 1) % 8);
(&m)->set_f83(51272 + (i * 1) % 8);
(&m)->set_f84(40 + (i * 1) % 8);
(&m)->set_f85(4405 + (i * 1) % 8);
(&m)->set_f86(53532 + (i * 1) % 8);
(&m)->set_f87(31684 + (i * 1) % 8);
(&m)->set_f88(18 + (i * 1) % 8);
(&m)->set_f89(11315533 + (i * 1) % 8);
(&m)->set_f90(85967355 + (i * 1) % 8);
(&m)->set_f91(1091499025 + (i * 1) % 8);
(&m)->set_f92(60193 + (i * 1) % 8);
(&m)->set_f93(124 + (i * 1) % 8);
(&m)->set_f94(521731529 + (i * 1) % 8);
(&m)->set_f95(13545247 + (i * 1) % 8);
(&m)->set_f96(28397 + (i * 1) % 8);
(&m)->set_f97(10493296 + (i * 1) % 8);
(&m)->set_f98(38931 + (i * 1) % 8);
(&m)->set_f99(105 + (i * 1) % 8);
(&m)->set_f100(3271978947 + (i * 1) % 8);
(&m)->set_f101(29455 + (i * 1) % 8);
(&m)->set_f102(94 + (i * 1) % 8);
(&m)->set_f103(4828945 + (i * 1) % 8);
(&m)->set_f104(7480587 + (i * 1) % 8);
(&m)->set_f105(3911733984 + (i * 1) % 8);
(&m)->set_f106(117 + (i * 1) % 8);
(&m)->set_f107(3922190723 + (i * 1) % 8);
(&m)->set_f108(3506090934 + (i * 1) % 8);
(&m)->set_f109(10281885 + (i * 1) % 8);
(&m)->set_f110(90 + (i * 1) % 8);
(&m)->set_f111(1261437573 + (i * 1) % 8);
(&m)->set_f112(13230 + (i * 1) % 8);
(&m)->set_f113(71 + (i * 1) % 8);
(&m)->set_f114(774 + (i * 1) % 8);
(&m)->set_f115(2012 + (i * 1) % 8);
(&m)->set_f116(43642 + (i * 1) % 8);
(&m)->set_f117(2207635 + (i * 1) % 8);
(&m)->set_f118(93 + (i * 1) % 8);
(&m)->set_f119(110 + (i * 1) % 8);
(&m)->set_f120(6921508 + (i * 1) % 8);
(&m)->set_f121(3621122041 + (i * 1) % 8);
(&m)->set_f122(3034153547 + (i * 1) % 8);
(&m)->set_f123(272719 + (i * 1) % 8);
(&m)->set_f124(16374482 + (i * 1) % 8);
(&m)->set_f125(2326468579 + (i * 1) % 8);
(&m)->set_f126(16776446 + (i * 1) % 8);
(&m)->set_f127(60 + (i * 1) % 8);
(&m)->set_f128(2165218 + (i * 1) % 8);
(&m)->set_f129(10013 + (i * 1) % 8);
(&m)->set_f130(1329348816 + (i * 1) % 8);
(&m)->set_f131(44539 + (i * 1) % 8);
(&m)->set_f132(63148 + (i * 1) % 8);
(&m)->set_f133(12946863 + (i * 1) % 8);
(&m)->set_f134(14426664 + (i * 1) % 8);
(&m)->set_f135(128 + (i * 1) % 8);
(&m)->set_f136(2421419231 + (i * 1) % 8);
(&m)->set_f137(2969830 + (i * 1) % 8);
(&m)->set_f138(3472454781 + (i * 1) % 8);
(&m)->set_f139(237834676 + (i * 1) % 8);
(&m)->set_f140(78 + (i * 1) % 8);
(&m)->set_f141(13686261 + (i * 1) % 8);
(&m)->set_f142(237 + (i * 1) % 8);
(&m)->set_f143(16163724 + (i * 1) % 8);
(&m)->set_f144(13 + (i * 1) % 8);
(&m)->set_f145(15 + (i * 1) % 8);
(&m)->set_f146(29482 + (i * 1) % 8);
(&m)->set_f147(2953442907 + (i * 1) % 8);
(&m)->set_f148(11007066 + (i * 1) % 8);
(&m)->set_f149(2001 + (i * 1) % 8);
(&m)->set_f150(38139 + (i * 1) % 8);
(&m)->set_f151(884398847 + (i * 1) % 8);
(&m)->set_f152(100 + (i * 1) % 8);
(&m)->set_f153(59268 + (i * 1) % 8);
(&m)->set_f154(3211459562 + (i * 1) % 8);
(&m)->set_f155(1811108654 + (i * 1) % 8);
(&m)->set_f156(56 + (i * 1) % 8);
(&m)->set_f157(15429 + (i * 1) % 8);
(&m)->set_f158(3969653706 + (i * 1) % 8);
(&m)->set_f159(12105 + (i * 1) % 8);
(&m)->set_f160(184763799 + (i * 1) % 8);
(&m)->set_f161(2201655192 + (i * 1) % 8);
(&m)->set_f162(46427 + (i * 1) % 8);
(&m)->set_f163(1447921349 + (i * 1) % 8);
(&m)->set_f164(2935 + (i * 1) % 8);
(&m)->set_f165(1947027835 + (i * 1) % 8);
(&m)->set_f166(31262 + (i * 1) % 8);
(&m)->set_f167(7639478 + (i * 1) % 8);
(&m)->set_f168(3608525942 + (i * 1) % 8);
(&m)->set_f169(13743441 + (i * 1) % 8);
(&m)->set_f170(10763639 + (i * 1) % 8);
(&m)->set_f171(14046631 + (i * 1) % 8);
(&m)->set_f172(1732065836 + (i * 1) % 8);
(&m)->set_f173(3418021 + (i * 1) % 8);
(&m)->set_f174(1268904088 + (i * 1) % 8);
(&m)->set_f175(230185 + (i * 1) % 8);
(&m)->set_f176(2711092641 + (i * 1) % 8);
(&m)->set_f177(5986 + (i * 1) % 8);
(&m)->set_f178(31706 + (i * 1) % 8);
(&m)->set_f179(88 + (i * 1) % 8);
(&m)->set_f180(3921 + (i * 1) % 8);
(&m)->set_f181(2277922918 + (i * 1) % 8);
(&m)->set_f182(6491878 + (i * 1) % 8);
(&m)->set_f183(3412169348 + (i * 1) % 8);
(&m)->set_f184(12221 + (i * 1) % 8);
(&m)->set_f185(4312412 + (i * 1) % 8);
(&m)->set_f186(98 + (i * 1) % 8);
(&m)->set_f187(10893 + (i * 1) % 8);
(&m)->set_f188(125161878 + (i * 1) % 8);
(&m)->set_f189(218 + (i * 1) % 8);
(&m)->set_f190(3439351454 + (i * 1) % 8);
(&m)->set_f191(4079005112 + (i * 1) % 8);
(&m)->set_f192(245 + (i * 1) % 8);
(&m)->set_f193(42609 + (i * 1) % 8);
(&m)->set_f194(25360 + (i * 1) % 8);
(&m)->set_f195(219 + (i * 1) % 8);
(&m)->set_f196(125298961 + (i * 1) % 8);
(&m)->set_f197(42591 + (i * 1) % 8);
(&m)->set_f198(84 + (i * 1) % 8);
(&m)->set_f199(214 + (i * 1) % 8);
(&m)->set_f200(208 + (i * 1) % 8);
(&m)->set_f201(250 + (i * 1) % 8);
(&m)->set_f202(16995 + (i * 1) % 8);
(&m)->set_f203(7074609 + (i * 1) % 8);
(&m)->set_f204(16687 + (i * 1) % 8);
(&m)->set_f205(132 + (i * 1) % 8);
(&m)->set_f206(250 + (i * 1) % 8);
(&m)->set_f207(1915303228 + (i * 1) % 8);
(&m)->set_f208(41082 + (i * 1) % 8);
(&m)->set_f209(141 + (i * 1) % 8);
(&m)->set_f210(874349662 + (i * 1) % 8);
(&m)->set_f211(62459 + (i * 1) % 8);
(&m)->set_f212(1564181331 + (i * 1) % 8);
(&m)->set_f213(12073222 + (i * 1) % 8);
(&m)->set_f214(3670551658 + (i * 1) % 8);
(&m)->set_f215(6777103 + (i * 1) % 8);
(&m)->set_f216(2 + (i * 1) % 8);
(&m)->set_f217(80 + (i * 1) % 8);
(&m)->set_f218(161 + (i * 1) % 8);
(&m)->set_f219(4950493 + (i * 1) % 8);
(&m)->set_f220(23 + (i * 1) % 8);
(&m)->set_f221(251 + (i * 1) % 8);
(&m)->set_f222(4289898561 + (i * 1) % 8);
(&m)->set_f223(247 + (i * 1) % 8);
(&m)->set_f224(1930900489 + (i * 1) % 8);
(&m)->set_f225(2586455 + (i * 1) % 8);
(&m)->set_f226(168659866 + (i * 1) % 8);
(&m)->set_f227(165 + (i * 1) % 8);
(&m)->set_f228(1087264 + (i * 1) % 8);
(&m)->set_f229(6415403 + (i * 1) % 8);
(&m)->set_f230(30 + (i * 1) % 8);
(&m)->set_f231(12228541 + (i * 1) % 8);
(&m)->set_f232(149 + (i * 1) % 8);
(&m)->set_f233(2126410383 + (i * 1) % 8);
(&m)->set_f234(11194 + (i * 1) % 8);
(&m)->set_f235(4802561 + (i * 1) % 8);
(&m)->set_f236(2699170523 + (i * 1) % 8);
(&m)->set_f237(1192587787 + (i * 1) % 8);
(&m)->set_f238(54 + (i * 1) % 8);
(&m)->set_f239(2776699189 + (i * 1) % 8);
(&m)->set_f240(14475176 + (i * 1) % 8);
(&m)->set_f241(55512 + (i * 1) % 8);
(&m)->set_f242(45509 + (i * 1) % 8);
(&m)->set_f243(11865550 + (i * 1) % 8);
(&m)->set_f244(55040 + (i * 1) % 8);
(&m)->set_f245(12168781 + (i * 1) % 8);
(&m)->set_f246(53704 + (i * 1) % 8);
(&m)->set_f247(21910 + (i * 1) % 8);
(&m)->set_f248(14444324 + (i * 1) % 8);
(&m)->set_f249(15329687 + (i * 1) % 8);
(&m)->set_f250(4260827392 + (i * 1) % 8);
(&m)->set_f251(2401092793 + (i * 1) % 8);
(&m)->set_f252(70 + (i * 1) % 8);
(&m)->set_f253(418359675 + (i * 1) % 8);
(&m)->set_f254(13224463 + (i * 1) % 8);
(&m)->set_f255(38602 + (i * 1) % 8);
(&m)->set_f256(9037618 + (i * 1) % 8);
(&m)->set_f257(2223655981 + (i * 1) % 8);
(&m)->set_f258(2975474341 + (i * 1) % 8);
(&m)->set_f259(3796889412 + (i * 1) % 8);
(&m)->set_f260(1720606109 + (i * 1) % 8);
(&m)->set_f261(4172725 + (i * 1) % 8);
(&m)->set_f262(1132277880 + (i * 1) % 8);
(&m)->set_f263(6453 + (i * 1) % 8);
(&m)->set_f264(232 + (i * 1) % 8);
(&m)->set_f265(14636959 + (i * 1) % 8);
(&m)->set_f266(219 + (i * 1) % 8);
(&m)->set_f267(20575 + (i * 1) % 8);
(&m)->set_f268(11 + (i * 1) % 8);
(&m)->set_f269(14 + (i * 1) % 8);
(&m)->set_f270(215 + (i * 1) % 8);
(&m)->set_f271(62093 + (i * 1) % 8);
(&m)->set_f272(10179617 + (i * 1) % 8);
(&m)->set_f273(14778459 + (i * 1) % 8);
(&m)->set_f274(3464551656 + (i * 1) % 8);
(&m)->set_f275(128 + (i * 1) % 8);
(&m)->set_f276(57271 + (i * 1) % 8);
(&m)->set_f277(189 + (i * 1) % 8);
(&m)->set_f278(6174651 + (i * 1) % 8);
(&m)->set_f279(6133892 + (i * 1) % 8);
(&m)->set_f280(159 + (i * 1) % 8);
(&m)->set_f281(83 + (i * 1) % 8);
(&m)->set_f282(3725235969 + (i * 1) % 8);
(&m)->set_f283(883934207 + (i * 1) % 8);
(&m)->set_f284(5255 + (i * 1) % 8);
(&m)->set_f285(43450 + (i * 1) % 8);
(&m)->set_f286(3667432431 + (i * 1) % 8);
(&m)->set_f287(138 + (i * 1) % 8);
(&m)->set_f288(54996 + (i * 1) % 8);
(&m)->set_f289(143 + (i * 1) % 8);
(&m)->set_f290(14484798 + (i * 1) % 8);
(&m)->set_f291(56 + (i * 1) % 8);
(&m)->set_f292(54633 + (i * 1) % 8);
(&m)->set_f293(1545075500 + (i * 1) % 8);
(&m)->set_f294(204858362 + (i * 1) % 8);
(&m)->set_f295(39441 + (i * 1) % 8);
(&m)->set_f296(21929 + (i * 1) % 8);
(&m)->set_f297(17900 + (i * 1) % 8);
(&m)->set_f298(152 + (i * 1) % 8);
(&m)->set_f299(5999343 + (i * 1) % 8);
(&m)->set_f300(2831341928 + (i * 1) % 8);
(&m)->set_f301(191 + (i * 1) % 8);
(&m)->set_f302(3285500188 + (i * 1) % 8);
(&m)->set_f303(3 + (i * 1) % 8);
(&m)->set_f304(4309910 + (i * 1) % 8);
(&m)->set_f305(20844 + (i * 1) % 8);
(&m)->set_f306(761512002 + (i * 1) % 8);
(&m)->set_f307(214 + (i * 1) % 8);
(&m)->set_f308(4775436 + (i * 1) % 8);
(&m)->set_f309(5024005 + (i * 1) % 8);
(&m)->set_f310(48129 + (i * 1) % 8);
(&m)->set_f311(15164688 + (i * 1) % 8);
(&m)->set_f312(11514579 + (i * 1) % 8);
(&m)->set_f313(14112 + (i * 1) % 8);
(&m)->set_f314(1571786611 + (i * 1) % 8);
(&m)->set_f315(57048 + (i * 1) % 8);
(&m)->set_f316(226 + (i * 1) % 8);
(&m)->set_f317(1744473846 + (i * 1) % 8);
(&m)->set_f318(45239 + (i * 1) % 8);
(&m)->set_f319(3054958307 + (i * 1) % 8);
(&m)->set_f320(9670 + (i * 1) % 8);
(&m)->set_f321(48084 + (i * 1) % 8);
(&m)->set_f322(3672730782 + (i * 1) % 8);
(&m)->set_f323(41 + (i * 1) % 8);
(&m)->set_f324(1992612387 + (i * 1) % 8);
(&m)->set_f325(1773772447 + (i * 1) % 8);
(&m)->set_f326(256114470 + (i * 1) % 8);
(&m)->set_f327(43 + (i * 1) % 8);
(&m)->set_f328(15972531 + (i * 1) % 8);
(&m)->set_f329(4233 + (i * 1) % 8);
(&m)->set_f330(12898575 + (i * 1) % 8);
(&m)->set_f331(2846987172 + (i * 1) % 8);
(&m)->set_f332(20407 + (i * 1) % 8);
(&m)->set_f333(2404826708 + (i * 1) % 8);
(&m)->set_f334(26616 + (i * 1) % 8);
(&m)->set_f335(237 + (i * 1) % 8);
(&m)->set_f336(14310 + (i * 1) % 8);
(&m)->set_f337(3916702504 + (i * 1) % 8);
(&m)->set_f338(2497146 + (i * 1) % 8);
(&m)->set_f339(51986 + (i * 1) % 8);
(&m)->set_f340(49 + (i * 1) % 8);
(&m)->set_f341(3009051187 + (i * 1) % 8);
(&m)->set_f342(224 + (i * 1) % 8);
(&m)->set_f343(169 + (i * 1) % 8);
(&m)->set_f344(1460616471 + (i * 1) % 8);
(&m)->set_f345(175 + (i * 1) % 8);
(&m)->set_f346(2300094593 + (i * 1) % 8);
(&m)->set_f347(40 + (i * 1) % 8);
(&m)->set_f348(47739 + (i * 1) % 8);
(&m)->set_f349(48586 + (i * 1) % 8);
(&m)->set_f350(49 + (i * 1) % 8);
(&m)->set_f351(80 + (i * 1) % 8);
(&m)->set_f352(15807921 + (i * 1) % 8);
(&m)->set_f353(1701233166 + (i * 1) % 8);
(&m)->set_f354(9591627 + (i * 1) % 8);
(&m)->set_f355(2141421151 + (i * 1) % 8);
(&m)->set_f356(2140642954 + (i * 1) % 8);
(&m)->set_f357(1641631422 + (i * 1) % 8);
(&m)->set_f358(54497 + (i * 1) % 8);
(&m)->set_f359(2974410850 + (i * 1) % 8);
(&m)->set_f360(714699407 + (i * 1) % 8);
(&m)->set_f361(926042378 + (i * 1) % 8);
(&m)->set_f362(521842598 + (i * 1) % 8);
(&m)->set_f363(1568721403 + (i * 1) % 8);
(&m)->set_f364(13631619 + (i * 1) % 8);
(&m)->set_f365(124 + (i * 1) % 8);
(&m)->set_f366(1476563354 + (i * 1) % 8);
(&m)->set_f367(2876567 + (i * 1) % 8);
(&m)->set_f368(13812 + (i * 1) % 8);
(&m)->set_f369(8951329 + (i * 1) % 8);
(&m)->set_f370(777338 + (i * 1) % 8);
(&m)->set_f371(29310 + (i * 1) % 8);
(&m)->set_f372(3865791941 + (i * 1) % 8);
(&m)->set_f373(228 + (i * 1) % 8);
(&m)->set_f374(2374434469 + (i * 1) % 8);
(&m)->set_f375(8 + (i * 1) % 8);
(&m)->set_f376(64 + (i * 1) % 8);
(&m)->set_f377(58 + (i * 1) % 8);
(&m)->set_f378(2793783477 + (i * 1) % 8);
(&m)->set_f379(1160146 + (i * 1) % 8);
(&m)->set_f380(2999055054 + (i * 1) % 8);
(&m)->set_f381(111355507 + (i * 1) % 8);
(&m)->set_f382(1333964358 + (i * 1) % 8);
(&m)->set_f383(114 + (i * 1) % 8);
(&m)->set_f384(3181586591 + (i * 1) % 8);
(&m)->set_f385(7990 + (i * 1) % 8);
(&m)->set_f386(8375169 + (i * 1) % 8);
(&m)->set_f387(222 + (i * 1) % 8);
(&m)->set_f388(101 + (i * 1) % 8);
(&m)->set_f389(655619561 + (i * 1) % 8);
(&m)->set_f390(9120728 + (i * 1) % 8);
(&m)->set_f391(44657 + (i * 1) % 8);
(&m)->set_f392(19253 + (i * 1) % 8);
(&m)->set_f393(11723285 + (i * 1) % 8);
(&m)->set_f394(3079539628 + (i * 1) % 8);
(&m)->set_f395(653823876 + (i * 1) % 8);
(&m)->set_f396(51201 + (i * 1) % 8);
(&m)->set_f397(2657945644 + (i * 1) % 8);
(&m)->set_f398(59142 + (i * 1) % 8);
(&m)->set_f399(498151 + (i * 1) % 8);
(&m)->set_f400(13224053 + (i * 1) % 8);


    messages.push_back(m);
  }

  //
  // Benchmark serialize.
  //
  // Warm-up.
 
  /* COMPRESSION WITH IAA COMMANDS
	uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&messages[i]);
	compress_with_IAA(ogByteStream, sizeof(messages[i]), compressed[i], BUFFER_SIZE, &comprOutputSize[i]);
	decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i]);
  */

  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    //if (!messages[i].SerializeToString(&outs[i])) {
    uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&messages[i]);
    if (compress_with_IAA(ogByteStream, sizeof(messages[i]), compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  std::chrono::steady_clock::time_point begin =
      std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
    //if (!messages[i].SerializeToString(&outs[i])) {
    uint8_t* ogByteStream = reinterpret_cast<uint8_t*>(&messages[i]);
    if (compress_with_IAA(ogByteStream, sizeof(messages[i]), compressed[i], BUFFER_SIZE, &comprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  auto took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "serialize took = "
            << took_ns / (messages.size() - kNofWarmUpIterations)
            << " [ns], size = " << comprOutputSize[0] << " Bytes" << std::endl;

  //
  // Benchmark deserialize.
  //
  std::vector<M> messages_out;
  for (size_t i = 0; i < messages.size(); ++i) messages_out.push_back(M());

  // Warm-up.
  for (size_t i = 0; i < kNofWarmUpIterations; ++i) {
    //if (!messages_out[i].ParseFromString(outs[i])) {
    if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }

  begin = std::chrono::steady_clock::now();
  for (size_t i = kNofWarmUpIterations; i < messages.size(); ++i) {
    //if (!messages_out[i].ParseFromString(outs[i])) {
    if (decompress_with_IAA(compressed[i], comprOutputSize[i], decompressed[i], BUFFER_SIZE, &decomprOutputSize[i])) {
      std::cerr << "Benchmark error." << std::endl;
      return -1;
    }
  }
  end = std::chrono::steady_clock::now();
  took_ns =
      std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
  std::cout << "deserialize took = "
            << took_ns / (messages.size() - kNofWarmUpIterations)
            << " [ns], size = " << decomprOutputSize[0] << " Bytes" << std::endl;

  // Compare.
  /*
  bool all_correct = true;
  for (size_t i = 0; i < messages.size() && all_correct; ++i)
    all_correct = google::protobuf::util::MessageDifferencer::Equals(
        messages[i], messages_out[i]);
  std::cout << (all_correct ? "ALL CORRECT" : "ERROR: DATA MISSMATCH")
            << std::endl;
  */

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  // free existing iaa jobs
	iaa_fini_jobs();

  return 0;
}
