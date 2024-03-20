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
	iaa_init_jobs(qpl_path_hardware);

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
(&m)->set_f1(114 + (i * 1) % 8);
(&m)->set_f2(11 + (i * 1) % 8);
(&m)->set_f3(2582158123 + (i * 1) % 8);
(&m)->set_f4(3403941869 + (i * 1) % 8);
(&m)->set_f5(763420001 + (i * 1) % 8);
(&m)->set_f6(26919 + (i * 1) % 8);
(&m)->set_f7(46350 + (i * 1) % 8);
(&m)->set_f8(64247 + (i * 1) % 8);
(&m)->set_f9(6652975 + (i * 1) % 8);
(&m)->set_f10(125 + (i * 1) % 8);
(&m)->set_f11(13958491 + (i * 1) % 8);
(&m)->set_f12(119 + (i * 1) % 8);
(&m)->set_f13(10945642 + (i * 1) % 8);
(&m)->set_f14(30830 + (i * 1) % 8);
(&m)->set_f15(700239563 + (i * 1) % 8);
(&m)->set_f16(3181946 + (i * 1) % 8);
(&m)->set_f17(12310867 + (i * 1) % 8);
(&m)->set_f18(150922172 + (i * 1) % 8);
(&m)->set_f19(4035415428 + (i * 1) % 8);
(&m)->set_f20(1563819307 + (i * 1) % 8);
(&m)->set_f21(222 + (i * 1) % 8);
(&m)->set_f22(2737747844 + (i * 1) % 8);
(&m)->set_f23(65 + (i * 1) % 8);
(&m)->set_f24(64417 + (i * 1) % 8);
(&m)->set_f25(3480579 + (i * 1) % 8);
(&m)->set_f26(8283382 + (i * 1) % 8);
(&m)->set_f27(1872128773 + (i * 1) % 8);
(&m)->set_f28(970928075 + (i * 1) % 8);
(&m)->set_f29(2338471662 + (i * 1) % 8);
(&m)->set_f30(446284854 + (i * 1) % 8);
(&m)->set_f31(2714386035 + (i * 1) % 8);
(&m)->set_f32(2302 + (i * 1) % 8);
(&m)->set_f33(1173733644 + (i * 1) % 8);
(&m)->set_f34(49354 + (i * 1) % 8);
(&m)->set_f35(7632940 + (i * 1) % 8);
(&m)->set_f36(22590 + (i * 1) % 8);
(&m)->set_f37(1762215976 + (i * 1) % 8);
(&m)->set_f38(2129269 + (i * 1) % 8);
(&m)->set_f39(336681263 + (i * 1) % 8);
(&m)->set_f40(24143 + (i * 1) % 8);
(&m)->set_f41(56 + (i * 1) % 8);
(&m)->set_f42(57 + (i * 1) % 8);
(&m)->set_f43(234 + (i * 1) % 8);
(&m)->set_f44(168 + (i * 1) % 8);
(&m)->set_f45(208 + (i * 1) % 8);
(&m)->set_f46(12679434 + (i * 1) % 8);
(&m)->set_f47(142 + (i * 1) % 8);
(&m)->set_f48(33483 + (i * 1) % 8);
(&m)->set_f49(182 + (i * 1) % 8);
(&m)->set_f50(1049680 + (i * 1) % 8);
(&m)->set_f51(59252 + (i * 1) % 8);
(&m)->set_f52(32248 + (i * 1) % 8);
(&m)->set_f53(117 + (i * 1) % 8);
(&m)->set_f54(48991 + (i * 1) % 8);
(&m)->set_f55(9 + (i * 1) % 8);
(&m)->set_f56(69 + (i * 1) % 8);
(&m)->set_f57(4082634735 + (i * 1) % 8);
(&m)->set_f58(7572115 + (i * 1) % 8);
(&m)->set_f59(218 + (i * 1) % 8);
(&m)->set_f60(0 + (i * 1) % 8);
(&m)->set_f61(7043506 + (i * 1) % 8);
(&m)->set_f62(226 + (i * 1) % 8);
(&m)->set_f63(9 + (i * 1) % 8);
(&m)->set_f64(44520 + (i * 1) % 8);
(&m)->set_f65(5251066 + (i * 1) % 8);
(&m)->set_f66(26 + (i * 1) % 8);
(&m)->set_f67(1992283944 + (i * 1) % 8);
(&m)->set_f68(15952855 + (i * 1) % 8);
(&m)->set_f69(1509437905 + (i * 1) % 8);
(&m)->set_f70(547108485 + (i * 1) % 8);
(&m)->set_f71(133 + (i * 1) % 8);
(&m)->set_f72(4323524 + (i * 1) % 8);
(&m)->set_f73(1152614604 + (i * 1) % 8);
(&m)->set_f74(19 + (i * 1) % 8);
(&m)->set_f75(10545 + (i * 1) % 8);
(&m)->set_f76(166 + (i * 1) % 8);
(&m)->set_f77(16653194 + (i * 1) % 8);
(&m)->set_f78(236 + (i * 1) % 8);
(&m)->set_f79(52 + (i * 1) % 8);
(&m)->set_f80(2600603 + (i * 1) % 8);
(&m)->set_f81(14004118 + (i * 1) % 8);
(&m)->set_f82(1304413544 + (i * 1) % 8);
(&m)->set_f83(11415009 + (i * 1) % 8);
(&m)->set_f84(4311407 + (i * 1) % 8);
(&m)->set_f85(9 + (i * 1) % 8);
(&m)->set_f86(9819124 + (i * 1) % 8);
(&m)->set_f87(2678169408 + (i * 1) % 8);
(&m)->set_f88(253 + (i * 1) % 8);
(&m)->set_f89(34931 + (i * 1) % 8);
(&m)->set_f90(64640 + (i * 1) % 8);
(&m)->set_f91(1854311290 + (i * 1) % 8);
(&m)->set_f92(42274 + (i * 1) % 8);
(&m)->set_f93(2502332631 + (i * 1) % 8);
(&m)->set_f94(2108771437 + (i * 1) % 8);
(&m)->set_f95(2832769 + (i * 1) % 8);
(&m)->set_f96(153 + (i * 1) % 8);
(&m)->set_f97(47635 + (i * 1) % 8);
(&m)->set_f98(148 + (i * 1) % 8);
(&m)->set_f99(37983 + (i * 1) % 8);
(&m)->set_f100(30126 + (i * 1) % 8);
(&m)->set_f101(16562157 + (i * 1) % 8);
(&m)->set_f102(39626 + (i * 1) % 8);
(&m)->set_f103(5147001 + (i * 1) % 8);
(&m)->set_f104(4752984 + (i * 1) % 8);
(&m)->set_f105(138 + (i * 1) % 8);
(&m)->set_f106(8385996 + (i * 1) % 8);
(&m)->set_f107(2670376758 + (i * 1) % 8);
(&m)->set_f108(232 + (i * 1) % 8);
(&m)->set_f109(81 + (i * 1) % 8);
(&m)->set_f110(4006018001 + (i * 1) % 8);
(&m)->set_f111(37508 + (i * 1) % 8);
(&m)->set_f112(3302704499 + (i * 1) % 8);
(&m)->set_f113(495872049 + (i * 1) % 8);
(&m)->set_f114(15997 + (i * 1) % 8);
(&m)->set_f115(25221 + (i * 1) % 8);
(&m)->set_f116(46 + (i * 1) % 8);
(&m)->set_f117(7065463 + (i * 1) % 8);
(&m)->set_f118(166 + (i * 1) % 8);
(&m)->set_f119(12 + (i * 1) % 8);
(&m)->set_f120(45761 + (i * 1) % 8);
(&m)->set_f121(36708 + (i * 1) % 8);
(&m)->set_f122(12838589 + (i * 1) % 8);
(&m)->set_f123(206 + (i * 1) % 8);
(&m)->set_f124(25 + (i * 1) % 8);
(&m)->set_f125(148 + (i * 1) % 8);
(&m)->set_f126(12979115 + (i * 1) % 8);
(&m)->set_f127(1 + (i * 1) % 8);
(&m)->set_f128(4844961 + (i * 1) % 8);
(&m)->set_f129(31074 + (i * 1) % 8);
(&m)->set_f130(27 + (i * 1) % 8);
(&m)->set_f131(3297702777 + (i * 1) % 8);
(&m)->set_f132(44196 + (i * 1) % 8);
(&m)->set_f133(74 + (i * 1) % 8);
(&m)->set_f134(45297 + (i * 1) % 8);
(&m)->set_f135(1396314 + (i * 1) % 8);
(&m)->set_f136(54369 + (i * 1) % 8);
(&m)->set_f137(12932765 + (i * 1) % 8);
(&m)->set_f138(9097 + (i * 1) % 8);
(&m)->set_f139(458476 + (i * 1) % 8);
(&m)->set_f140(11461070 + (i * 1) % 8);
(&m)->set_f141(62173 + (i * 1) % 8);
(&m)->set_f142(5400493 + (i * 1) % 8);
(&m)->set_f143(176 + (i * 1) % 8);
(&m)->set_f144(622150664 + (i * 1) % 8);
(&m)->set_f145(222 + (i * 1) % 8);
(&m)->set_f146(49 + (i * 1) % 8);
(&m)->set_f147(155 + (i * 1) % 8);
(&m)->set_f148(1536263125 + (i * 1) % 8);
(&m)->set_f149(150 + (i * 1) % 8);
(&m)->set_f150(223 + (i * 1) % 8);
(&m)->set_f151(8803669 + (i * 1) % 8);
(&m)->set_f152(13011211 + (i * 1) % 8);
(&m)->set_f153(1169897632 + (i * 1) % 8);
(&m)->set_f154(12770019 + (i * 1) % 8);
(&m)->set_f155(3927360919 + (i * 1) % 8);
(&m)->set_f156(9949 + (i * 1) % 8);
(&m)->set_f157(3944050 + (i * 1) % 8);
(&m)->set_f158(7893479 + (i * 1) % 8);
(&m)->set_f159(35797 + (i * 1) % 8);
(&m)->set_f160(14147575 + (i * 1) % 8);
(&m)->set_f161(4873600 + (i * 1) % 8);
(&m)->set_f162(203 + (i * 1) % 8);
(&m)->set_f163(2829022653 + (i * 1) % 8);
(&m)->set_f164(2479429443 + (i * 1) % 8);
(&m)->set_f165(1825787566 + (i * 1) % 8);
(&m)->set_f166(132 + (i * 1) % 8);
(&m)->set_f167(5580937 + (i * 1) % 8);
(&m)->set_f168(1482532259 + (i * 1) % 8);
(&m)->set_f169(53620 + (i * 1) % 8);
(&m)->set_f170(58009 + (i * 1) % 8);
(&m)->set_f171(4267344 + (i * 1) % 8);
(&m)->set_f172(157 + (i * 1) % 8);
(&m)->set_f173(150 + (i * 1) % 8);
(&m)->set_f174(13208608 + (i * 1) % 8);
(&m)->set_f175(187 + (i * 1) % 8);
(&m)->set_f176(229 + (i * 1) % 8);
(&m)->set_f177(1217877037 + (i * 1) % 8);
(&m)->set_f178(111 + (i * 1) % 8);
(&m)->set_f179(29772 + (i * 1) % 8);
(&m)->set_f180(39431 + (i * 1) % 8);
(&m)->set_f181(4218881049 + (i * 1) % 8);
(&m)->set_f182(1920772211 + (i * 1) % 8);
(&m)->set_f183(75287454 + (i * 1) % 8);
(&m)->set_f184(17381 + (i * 1) % 8);
(&m)->set_f185(1347217831 + (i * 1) % 8);
(&m)->set_f186(161 + (i * 1) % 8);
(&m)->set_f187(9564077 + (i * 1) % 8);
(&m)->set_f188(7018345 + (i * 1) % 8);
(&m)->set_f189(3916913747 + (i * 1) % 8);
(&m)->set_f190(12281454 + (i * 1) % 8);
(&m)->set_f191(1084541128 + (i * 1) % 8);
(&m)->set_f192(92 + (i * 1) % 8);
(&m)->set_f193(2495945032 + (i * 1) % 8);
(&m)->set_f194(17763 + (i * 1) % 8);
(&m)->set_f195(77 + (i * 1) % 8);
(&m)->set_f196(221 + (i * 1) % 8);
(&m)->set_f197(2460134754 + (i * 1) % 8);
(&m)->set_f198(11874122 + (i * 1) % 8);
(&m)->set_f199(22885 + (i * 1) % 8);
(&m)->set_f200(108 + (i * 1) % 8);
(&m)->set_f201(2495059 + (i * 1) % 8);
(&m)->set_f202(51950 + (i * 1) % 8);
(&m)->set_f203(59815 + (i * 1) % 8);
(&m)->set_f204(4763 + (i * 1) % 8);
(&m)->set_f205(43 + (i * 1) % 8);
(&m)->set_f206(23562 + (i * 1) % 8);
(&m)->set_f207(247 + (i * 1) % 8);
(&m)->set_f208(65 + (i * 1) % 8);
(&m)->set_f209(19097 + (i * 1) % 8);
(&m)->set_f210(3452535718 + (i * 1) % 8);
(&m)->set_f211(48 + (i * 1) % 8);
(&m)->set_f212(1375 + (i * 1) % 8);
(&m)->set_f213(3483215933 + (i * 1) % 8);
(&m)->set_f214(105 + (i * 1) % 8);
(&m)->set_f215(35303 + (i * 1) % 8);
(&m)->set_f216(3456917 + (i * 1) % 8);
(&m)->set_f217(5090 + (i * 1) % 8);
(&m)->set_f218(61256 + (i * 1) % 8);
(&m)->set_f219(19496 + (i * 1) % 8);
(&m)->set_f220(253 + (i * 1) % 8);
(&m)->set_f221(16262871 + (i * 1) % 8);
(&m)->set_f222(6617502 + (i * 1) % 8);
(&m)->set_f223(149 + (i * 1) % 8);
(&m)->set_f224(4729255 + (i * 1) % 8);
(&m)->set_f225(210 + (i * 1) % 8);
(&m)->set_f226(51754 + (i * 1) % 8);
(&m)->set_f227(2305527559 + (i * 1) % 8);
(&m)->set_f228(46680 + (i * 1) % 8);
(&m)->set_f229(42117 + (i * 1) % 8);
(&m)->set_f230(22456 + (i * 1) % 8);
(&m)->set_f231(18590 + (i * 1) % 8);
(&m)->set_f232(151 + (i * 1) % 8);
(&m)->set_f233(60942 + (i * 1) % 8);
(&m)->set_f234(64009 + (i * 1) % 8);
(&m)->set_f235(15687401 + (i * 1) % 8);
(&m)->set_f236(16415386 + (i * 1) % 8);
(&m)->set_f237(5147568 + (i * 1) % 8);
(&m)->set_f238(170 + (i * 1) % 8);
(&m)->set_f239(10153324 + (i * 1) % 8);
(&m)->set_f240(1605542029 + (i * 1) % 8);
(&m)->set_f241(2789608 + (i * 1) % 8);
(&m)->set_f242(46 + (i * 1) % 8);
(&m)->set_f243(504118156 + (i * 1) % 8);
(&m)->set_f244(34665 + (i * 1) % 8);
(&m)->set_f245(327467903 + (i * 1) % 8);
(&m)->set_f246(47904 + (i * 1) % 8);
(&m)->set_f247(73 + (i * 1) % 8);
(&m)->set_f248(237 + (i * 1) % 8);
(&m)->set_f249(12449393 + (i * 1) % 8);
(&m)->set_f250(3719577791 + (i * 1) % 8);
(&m)->set_f251(464799505 + (i * 1) % 8);
(&m)->set_f252(96 + (i * 1) % 8);
(&m)->set_f253(60910 + (i * 1) % 8);
(&m)->set_f254(39702 + (i * 1) % 8);
(&m)->set_f255(204 + (i * 1) % 8);
(&m)->set_f256(37893 + (i * 1) % 8);
(&m)->set_f257(5662318 + (i * 1) % 8);
(&m)->set_f258(12296 + (i * 1) % 8);
(&m)->set_f259(2543314 + (i * 1) % 8);
(&m)->set_f260(87 + (i * 1) % 8);
(&m)->set_f261(3009021088 + (i * 1) % 8);
(&m)->set_f262(9051694 + (i * 1) % 8);
(&m)->set_f263(1759895508 + (i * 1) % 8);
(&m)->set_f264(10538821 + (i * 1) % 8);
(&m)->set_f265(128 + (i * 1) % 8);
(&m)->set_f266(6525064 + (i * 1) % 8);
(&m)->set_f267(1982932959 + (i * 1) % 8);
(&m)->set_f268(58720 + (i * 1) % 8);
(&m)->set_f269(671129389 + (i * 1) % 8);
(&m)->set_f270(230 + (i * 1) % 8);
(&m)->set_f271(61331 + (i * 1) % 8);
(&m)->set_f272(197 + (i * 1) % 8);
(&m)->set_f273(9 + (i * 1) % 8);
(&m)->set_f274(97 + (i * 1) % 8);
(&m)->set_f275(69 + (i * 1) % 8);
(&m)->set_f276(3662097300 + (i * 1) % 8);
(&m)->set_f277(32505 + (i * 1) % 8);
(&m)->set_f278(240 + (i * 1) % 8);
(&m)->set_f279(48692 + (i * 1) % 8);
(&m)->set_f280(3591 + (i * 1) % 8);
(&m)->set_f281(19166 + (i * 1) % 8);
(&m)->set_f282(4435282 + (i * 1) % 8);
(&m)->set_f283(2296045723 + (i * 1) % 8);
(&m)->set_f284(1942 + (i * 1) % 8);
(&m)->set_f285(5250512 + (i * 1) % 8);
(&m)->set_f286(218 + (i * 1) % 8);
(&m)->set_f287(98 + (i * 1) % 8);
(&m)->set_f288(5519 + (i * 1) % 8);
(&m)->set_f289(9456217 + (i * 1) % 8);
(&m)->set_f290(138 + (i * 1) % 8);
(&m)->set_f291(16944 + (i * 1) % 8);
(&m)->set_f292(23869 + (i * 1) % 8);
(&m)->set_f293(2117175 + (i * 1) % 8);
(&m)->set_f294(15961821 + (i * 1) % 8);
(&m)->set_f295(49632 + (i * 1) % 8);
(&m)->set_f296(16448 + (i * 1) % 8);
(&m)->set_f297(104 + (i * 1) % 8);
(&m)->set_f298(5379448 + (i * 1) % 8);
(&m)->set_f299(152 + (i * 1) % 8);
(&m)->set_f300(3684107295 + (i * 1) % 8);
(&m)->set_f301(223 + (i * 1) % 8);
(&m)->set_f302(1197358381 + (i * 1) % 8);
(&m)->set_f303(3446654622 + (i * 1) % 8);
(&m)->set_f304(242 + (i * 1) % 8);
(&m)->set_f305(60 + (i * 1) % 8);
(&m)->set_f306(3774979661 + (i * 1) % 8);
(&m)->set_f307(25 + (i * 1) % 8);
(&m)->set_f308(62206 + (i * 1) % 8);
(&m)->set_f309(62179 + (i * 1) % 8);
(&m)->set_f310(164 + (i * 1) % 8);
(&m)->set_f311(1366597201 + (i * 1) % 8);
(&m)->set_f312(16647286 + (i * 1) % 8);
(&m)->set_f313(20825 + (i * 1) % 8);
(&m)->set_f314(2883953517 + (i * 1) % 8);
(&m)->set_f315(251 + (i * 1) % 8);
(&m)->set_f316(11699252 + (i * 1) % 8);
(&m)->set_f317(29 + (i * 1) % 8);
(&m)->set_f318(2351282620 + (i * 1) % 8);
(&m)->set_f319(1558134166 + (i * 1) % 8);
(&m)->set_f320(112 + (i * 1) % 8);
(&m)->set_f321(10327949 + (i * 1) % 8);
(&m)->set_f322(3815308 + (i * 1) % 8);
(&m)->set_f323(2055431 + (i * 1) % 8);
(&m)->set_f324(14432256 + (i * 1) % 8);
(&m)->set_f325(41 + (i * 1) % 8);
(&m)->set_f326(3356589 + (i * 1) % 8);
(&m)->set_f327(39 + (i * 1) % 8);
(&m)->set_f328(185 + (i * 1) % 8);
(&m)->set_f329(53345 + (i * 1) % 8);
(&m)->set_f330(215 + (i * 1) % 8);
(&m)->set_f331(54696 + (i * 1) % 8);
(&m)->set_f332(2761253515 + (i * 1) % 8);
(&m)->set_f333(175 + (i * 1) % 8);
(&m)->set_f334(1201138184 + (i * 1) % 8);
(&m)->set_f335(122 + (i * 1) % 8);
(&m)->set_f336(63722 + (i * 1) % 8);
(&m)->set_f337(178 + (i * 1) % 8);
(&m)->set_f338(71 + (i * 1) % 8);
(&m)->set_f339(3819911768 + (i * 1) % 8);
(&m)->set_f340(2977232020 + (i * 1) % 8);
(&m)->set_f341(42 + (i * 1) % 8);
(&m)->set_f342(14540191 + (i * 1) % 8);
(&m)->set_f343(167 + (i * 1) % 8);
(&m)->set_f344(1099052767 + (i * 1) % 8);
(&m)->set_f345(220 + (i * 1) % 8);
(&m)->set_f346(114 + (i * 1) % 8);
(&m)->set_f347(16739411 + (i * 1) % 8);
(&m)->set_f348(38824 + (i * 1) % 8);
(&m)->set_f349(4460268 + (i * 1) % 8);
(&m)->set_f350(3122468092 + (i * 1) % 8);
(&m)->set_f351(12907865 + (i * 1) % 8);
(&m)->set_f352(1041209668 + (i * 1) % 8);
(&m)->set_f353(156 + (i * 1) % 8);
(&m)->set_f354(3489781169 + (i * 1) % 8);
(&m)->set_f355(206 + (i * 1) % 8);
(&m)->set_f356(2508211827 + (i * 1) % 8);
(&m)->set_f357(13498991 + (i * 1) % 8);
(&m)->set_f358(4120075761 + (i * 1) % 8);
(&m)->set_f359(18777 + (i * 1) % 8);
(&m)->set_f360(92 + (i * 1) % 8);
(&m)->set_f361(2811579 + (i * 1) % 8);
(&m)->set_f362(211 + (i * 1) % 8);
(&m)->set_f363(193 + (i * 1) % 8);
(&m)->set_f364(2480538 + (i * 1) % 8);
(&m)->set_f365(161 + (i * 1) % 8);
(&m)->set_f366(217 + (i * 1) % 8);
(&m)->set_f367(8713953 + (i * 1) % 8);
(&m)->set_f368(12111446 + (i * 1) % 8);
(&m)->set_f369(41961 + (i * 1) % 8);
(&m)->set_f370(55250 + (i * 1) % 8);
(&m)->set_f371(3738385513 + (i * 1) % 8);
(&m)->set_f372(28 + (i * 1) % 8);
(&m)->set_f373(61879 + (i * 1) % 8);
(&m)->set_f374(14228457 + (i * 1) % 8);
(&m)->set_f375(236 + (i * 1) % 8);
(&m)->set_f376(2506321 + (i * 1) % 8);
(&m)->set_f377(3496575 + (i * 1) % 8);
(&m)->set_f378(15529410 + (i * 1) % 8);
(&m)->set_f379(1094916558 + (i * 1) % 8);
(&m)->set_f380(13021339 + (i * 1) % 8);
(&m)->set_f381(3380780 + (i * 1) % 8);
(&m)->set_f382(16560021 + (i * 1) % 8);
(&m)->set_f383(2761344799 + (i * 1) % 8);
(&m)->set_f384(1145637 + (i * 1) % 8);
(&m)->set_f385(56 + (i * 1) % 8);
(&m)->set_f386(3545561421 + (i * 1) % 8);
(&m)->set_f387(1114020 + (i * 1) % 8);
(&m)->set_f388(3553021814 + (i * 1) % 8);
(&m)->set_f389(1 + (i * 1) % 8);
(&m)->set_f390(13548 + (i * 1) % 8);
(&m)->set_f391(57087 + (i * 1) % 8);
(&m)->set_f392(16 + (i * 1) % 8);
(&m)->set_f393(6568367 + (i * 1) % 8);
(&m)->set_f394(49789 + (i * 1) % 8);
(&m)->set_f395(3663373 + (i * 1) % 8);
(&m)->set_f396(58979 + (i * 1) % 8);
(&m)->set_f397(42131 + (i * 1) % 8);
(&m)->set_f398(983698531 + (i * 1) % 8);
(&m)->set_f399(11608 + (i * 1) % 8);
(&m)->set_f400(52 + (i * 1) % 8);


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
