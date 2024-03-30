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
(&m)->set_f1(2237455955 + (i * 1) % 8);
(&m)->set_f2(82 + (i * 1) % 8);
(&m)->set_f3(14121666 + (i * 1) % 8);
(&m)->set_f4(218 + (i * 1) % 8);
(&m)->set_f5(107 + (i * 1) % 8);
(&m)->set_f6(1722065077 + (i * 1) % 8);
(&m)->set_f7(39153 + (i * 1) % 8);
(&m)->set_f8(204 + (i * 1) % 8);
(&m)->set_f9(183 + (i * 1) % 8);
(&m)->set_f10(203 + (i * 1) % 8);
(&m)->set_f11(57964 + (i * 1) % 8);
(&m)->set_f12(8141658 + (i * 1) % 8);
(&m)->set_f13(29 + (i * 1) % 8);
(&m)->set_f14(63566268 + (i * 1) % 8);
(&m)->set_f15(48587 + (i * 1) % 8);
(&m)->set_f16(213 + (i * 1) % 8);
(&m)->set_f17(155 + (i * 1) % 8);
(&m)->set_f18(8 + (i * 1) % 8);
(&m)->set_f19(1382933 + (i * 1) % 8);
(&m)->set_f20(16 + (i * 1) % 8);
(&m)->set_f21(179 + (i * 1) % 8);
(&m)->set_f22(4033 + (i * 1) % 8);
(&m)->set_f23(7916395 + (i * 1) % 8);
(&m)->set_f24(71 + (i * 1) % 8);
(&m)->set_f25(118 + (i * 1) % 8);
(&m)->set_f26(245 + (i * 1) % 8);
(&m)->set_f27(216 + (i * 1) % 8);
(&m)->set_f28(2838804863 + (i * 1) % 8);
(&m)->set_f29(112 + (i * 1) % 8);
(&m)->set_f30(689910118 + (i * 1) % 8);
(&m)->set_f31(498430342 + (i * 1) % 8);
(&m)->set_f32(55691 + (i * 1) % 8);
(&m)->set_f33(3862621 + (i * 1) % 8);
(&m)->set_f34(23592 + (i * 1) % 8);
(&m)->set_f35(44145 + (i * 1) % 8);
(&m)->set_f36(172 + (i * 1) % 8);
(&m)->set_f37(229 + (i * 1) % 8);
(&m)->set_f38(2289134 + (i * 1) % 8);
(&m)->set_f39(3920694 + (i * 1) % 8);
(&m)->set_f40(2066 + (i * 1) % 8);
(&m)->set_f41(13036 + (i * 1) % 8);
(&m)->set_f42(1472579 + (i * 1) % 8);
(&m)->set_f43(233 + (i * 1) % 8);
(&m)->set_f44(37092 + (i * 1) % 8);
(&m)->set_f45(188 + (i * 1) % 8);
(&m)->set_f46(129 + (i * 1) % 8);
(&m)->set_f47(124 + (i * 1) % 8);
(&m)->set_f48(14370090 + (i * 1) % 8);
(&m)->set_f49(8074250 + (i * 1) % 8);
(&m)->set_f50(210 + (i * 1) % 8);
(&m)->set_f51(72 + (i * 1) % 8);
(&m)->set_f52(1198732269 + (i * 1) % 8);
(&m)->set_f53(60466 + (i * 1) % 8);
(&m)->set_f54(1031296094 + (i * 1) % 8);
(&m)->set_f55(2174920 + (i * 1) % 8);
(&m)->set_f56(1783838644 + (i * 1) % 8);
(&m)->set_f57(13734737 + (i * 1) % 8);
(&m)->set_f58(87 + (i * 1) % 8);
(&m)->set_f59(4189780102 + (i * 1) % 8);
(&m)->set_f60(62063 + (i * 1) % 8);
(&m)->set_f61(10192547 + (i * 1) % 8);
(&m)->set_f62(1112725298 + (i * 1) % 8);
(&m)->set_f63(232 + (i * 1) % 8);
(&m)->set_f64(9439 + (i * 1) % 8);
(&m)->set_f65(603018542 + (i * 1) % 8);
(&m)->set_f66(2805851 + (i * 1) % 8);
(&m)->set_f67(1206207140 + (i * 1) % 8);
(&m)->set_f68(10355244 + (i * 1) % 8);
(&m)->set_f69(251 + (i * 1) % 8);
(&m)->set_f70(13216739 + (i * 1) % 8);
(&m)->set_f71(218 + (i * 1) % 8);
(&m)->set_f72(93 + (i * 1) % 8);
(&m)->set_f73(10151 + (i * 1) % 8);
(&m)->set_f74(64158 + (i * 1) % 8);
(&m)->set_f75(250 + (i * 1) % 8);
(&m)->set_f76(247 + (i * 1) % 8);
(&m)->set_f77(3043177522 + (i * 1) % 8);
(&m)->set_f78(54343 + (i * 1) % 8);
(&m)->set_f79(17357 + (i * 1) % 8);
(&m)->set_f80(584120719 + (i * 1) % 8);
(&m)->set_f81(1579401453 + (i * 1) % 8);
(&m)->set_f82(4418382 + (i * 1) % 8);
(&m)->set_f83(7388 + (i * 1) % 8);
(&m)->set_f84(254 + (i * 1) % 8);
(&m)->set_f85(225 + (i * 1) % 8);
(&m)->set_f86(175 + (i * 1) % 8);
(&m)->set_f87(80 + (i * 1) % 8);
(&m)->set_f88(1362826150 + (i * 1) % 8);
(&m)->set_f89(15628207 + (i * 1) % 8);
(&m)->set_f90(1652181770 + (i * 1) % 8);
(&m)->set_f91(27069 + (i * 1) % 8);
(&m)->set_f92(1074091718 + (i * 1) % 8);
(&m)->set_f93(28 + (i * 1) % 8);
(&m)->set_f94(166 + (i * 1) % 8);
(&m)->set_f95(19892 + (i * 1) % 8);
(&m)->set_f96(1990337 + (i * 1) % 8);
(&m)->set_f97(54401 + (i * 1) % 8);
(&m)->set_f98(8621062 + (i * 1) % 8);
(&m)->set_f99(849300080 + (i * 1) % 8);
(&m)->set_f100(93 + (i * 1) % 8);
(&m)->set_f101(179 + (i * 1) % 8);
(&m)->set_f102(238 + (i * 1) % 8);
(&m)->set_f103(2793717503 + (i * 1) % 8);
(&m)->set_f104(23664 + (i * 1) % 8);
(&m)->set_f105(19872 + (i * 1) % 8);
(&m)->set_f106(22581 + (i * 1) % 8);
(&m)->set_f107(9551222 + (i * 1) % 8);
(&m)->set_f108(7063 + (i * 1) % 8);
(&m)->set_f109(104 + (i * 1) % 8);
(&m)->set_f110(2675207323 + (i * 1) % 8);
(&m)->set_f111(9657915 + (i * 1) % 8);
(&m)->set_f112(1719810913 + (i * 1) % 8);
(&m)->set_f113(1918322 + (i * 1) % 8);
(&m)->set_f114(861 + (i * 1) % 8);
(&m)->set_f115(101 + (i * 1) % 8);
(&m)->set_f116(15092124 + (i * 1) % 8);
(&m)->set_f117(229 + (i * 1) % 8);
(&m)->set_f118(1871 + (i * 1) % 8);
(&m)->set_f119(64064 + (i * 1) % 8);
(&m)->set_f120(21703 + (i * 1) % 8);
(&m)->set_f121(25913 + (i * 1) % 8);
(&m)->set_f122(160 + (i * 1) % 8);
(&m)->set_f123(2719754524 + (i * 1) % 8);
(&m)->set_f124(704979912 + (i * 1) % 8);
(&m)->set_f125(3465855710 + (i * 1) % 8);
(&m)->set_f126(14188882 + (i * 1) % 8);
(&m)->set_f127(3975981174 + (i * 1) % 8);
(&m)->set_f128(129 + (i * 1) % 8);
(&m)->set_f129(251 + (i * 1) % 8);
(&m)->set_f130(2574530124 + (i * 1) % 8);
(&m)->set_f131(43805 + (i * 1) % 8);
(&m)->set_f132(1593508103 + (i * 1) % 8);
(&m)->set_f133(473591873 + (i * 1) % 8);
(&m)->set_f134(150 + (i * 1) % 8);
(&m)->set_f135(9668380 + (i * 1) % 8);
(&m)->set_f136(369447813 + (i * 1) % 8);
(&m)->set_f137(40 + (i * 1) % 8);
(&m)->set_f138(4168836 + (i * 1) % 8);
(&m)->set_f139(2869257609 + (i * 1) % 8);
(&m)->set_f140(153 + (i * 1) % 8);
(&m)->set_f141(227216177 + (i * 1) % 8);
(&m)->set_f142(1173346719 + (i * 1) % 8);
(&m)->set_f143(58392 + (i * 1) % 8);
(&m)->set_f144(49699 + (i * 1) % 8);
(&m)->set_f145(22423 + (i * 1) % 8);
(&m)->set_f146(337074071 + (i * 1) % 8);
(&m)->set_f147(3277650259 + (i * 1) % 8);
(&m)->set_f148(189 + (i * 1) % 8);
(&m)->set_f149(2983307468 + (i * 1) % 8);
(&m)->set_f150(10956861 + (i * 1) % 8);
(&m)->set_f151(1128861017 + (i * 1) % 8);
(&m)->set_f152(6457882 + (i * 1) % 8);
(&m)->set_f153(31730 + (i * 1) % 8);
(&m)->set_f154(10308610 + (i * 1) % 8);
(&m)->set_f155(3934625073 + (i * 1) % 8);
(&m)->set_f156(55222 + (i * 1) % 8);
(&m)->set_f157(15287968 + (i * 1) % 8);
(&m)->set_f158(50746 + (i * 1) % 8);
(&m)->set_f159(495846847 + (i * 1) % 8);
(&m)->set_f160(2640749665 + (i * 1) % 8);
(&m)->set_f161(51240 + (i * 1) % 8);
(&m)->set_f162(658973206 + (i * 1) % 8);
(&m)->set_f163(10699383 + (i * 1) % 8);
(&m)->set_f164(67 + (i * 1) % 8);
(&m)->set_f165(30621 + (i * 1) % 8);
(&m)->set_f166(4672965 + (i * 1) % 8);
(&m)->set_f167(51880 + (i * 1) % 8);
(&m)->set_f168(1907 + (i * 1) % 8);
(&m)->set_f169(4652567 + (i * 1) % 8);
(&m)->set_f170(1005494970 + (i * 1) % 8);
(&m)->set_f171(5532628 + (i * 1) % 8);
(&m)->set_f172(4590550 + (i * 1) % 8);
(&m)->set_f173(3531147009 + (i * 1) % 8);
(&m)->set_f174(32103 + (i * 1) % 8);
(&m)->set_f175(6011808 + (i * 1) % 8);
(&m)->set_f176(711817 + (i * 1) % 8);
(&m)->set_f177(34720 + (i * 1) % 8);
(&m)->set_f178(16848 + (i * 1) % 8);
(&m)->set_f179(13392302 + (i * 1) % 8);
(&m)->set_f180(55 + (i * 1) % 8);
(&m)->set_f181(47915 + (i * 1) % 8);
(&m)->set_f182(112 + (i * 1) % 8);
(&m)->set_f183(1599749561 + (i * 1) % 8);
(&m)->set_f184(16646676 + (i * 1) % 8);
(&m)->set_f185(205244622 + (i * 1) % 8);
(&m)->set_f186(10399434 + (i * 1) % 8);
(&m)->set_f187(139 + (i * 1) % 8);
(&m)->set_f188(4232514708 + (i * 1) % 8);
(&m)->set_f189(3423864660 + (i * 1) % 8);
(&m)->set_f190(15442045 + (i * 1) % 8);
(&m)->set_f191(13411661 + (i * 1) % 8);
(&m)->set_f192(3105433545 + (i * 1) % 8);
(&m)->set_f193(7212570 + (i * 1) % 8);
(&m)->set_f194(8684444 + (i * 1) % 8);
(&m)->set_f195(182 + (i * 1) % 8);
(&m)->set_f196(53486 + (i * 1) % 8);
(&m)->set_f197(3904949 + (i * 1) % 8);
(&m)->set_f198(13469479 + (i * 1) % 8);
(&m)->set_f199(6 + (i * 1) % 8);
(&m)->set_f200(2177806376 + (i * 1) % 8);
(&m)->set_f201(101 + (i * 1) % 8);
(&m)->set_f202(3685467409 + (i * 1) % 8);
(&m)->set_f203(23725 + (i * 1) % 8);
(&m)->set_f204(4734 + (i * 1) % 8);
(&m)->set_f205(1920266666 + (i * 1) % 8);
(&m)->set_f206(58 + (i * 1) % 8);
(&m)->set_f207(32230 + (i * 1) % 8);
(&m)->set_f208(11981 + (i * 1) % 8);
(&m)->set_f209(83 + (i * 1) % 8);
(&m)->set_f210(2145308311 + (i * 1) % 8);
(&m)->set_f211(64668 + (i * 1) % 8);
(&m)->set_f212(107 + (i * 1) % 8);
(&m)->set_f213(112 + (i * 1) % 8);
(&m)->set_f214(3281061 + (i * 1) % 8);
(&m)->set_f215(3689952 + (i * 1) % 8);
(&m)->set_f216(15657542 + (i * 1) % 8);
(&m)->set_f217(46218 + (i * 1) % 8);
(&m)->set_f218(5818193 + (i * 1) % 8);
(&m)->set_f219(93860161 + (i * 1) % 8);
(&m)->set_f220(64005 + (i * 1) % 8);
(&m)->set_f221(2317465257 + (i * 1) % 8);
(&m)->set_f222(969103570 + (i * 1) % 8);
(&m)->set_f223(9703 + (i * 1) % 8);
(&m)->set_f224(14054664 + (i * 1) % 8);
(&m)->set_f225(1098853378 + (i * 1) % 8);
(&m)->set_f226(37317 + (i * 1) % 8);
(&m)->set_f227(15342227 + (i * 1) % 8);
(&m)->set_f228(14 + (i * 1) % 8);
(&m)->set_f229(108 + (i * 1) % 8);
(&m)->set_f230(6476 + (i * 1) % 8);
(&m)->set_f231(43 + (i * 1) % 8);
(&m)->set_f232(41327 + (i * 1) % 8);
(&m)->set_f233(12304337 + (i * 1) % 8);
(&m)->set_f234(114 + (i * 1) % 8);
(&m)->set_f235(255 + (i * 1) % 8);
(&m)->set_f236(5235750 + (i * 1) % 8);
(&m)->set_f237(10442623 + (i * 1) % 8);
(&m)->set_f238(4009044463 + (i * 1) % 8);
(&m)->set_f239(11692779 + (i * 1) % 8);
(&m)->set_f240(2778079612 + (i * 1) % 8);
(&m)->set_f241(35478 + (i * 1) % 8);
(&m)->set_f242(73 + (i * 1) % 8);
(&m)->set_f243(80 + (i * 1) % 8);
(&m)->set_f244(208 + (i * 1) % 8);
(&m)->set_f245(55216 + (i * 1) % 8);
(&m)->set_f246(40164 + (i * 1) % 8);
(&m)->set_f247(60962 + (i * 1) % 8);
(&m)->set_f248(46357 + (i * 1) % 8);
(&m)->set_f249(9274721 + (i * 1) % 8);
(&m)->set_f250(6293147 + (i * 1) % 8);
(&m)->set_f251(137 + (i * 1) % 8);
(&m)->set_f252(2946186 + (i * 1) % 8);
(&m)->set_f253(24374 + (i * 1) % 8);
(&m)->set_f254(37 + (i * 1) % 8);
(&m)->set_f255(16412345 + (i * 1) % 8);
(&m)->set_f256(1848 + (i * 1) % 8);
(&m)->set_f257(3133025215 + (i * 1) % 8);
(&m)->set_f258(5787715 + (i * 1) % 8);
(&m)->set_f259(215 + (i * 1) % 8);
(&m)->set_f260(91 + (i * 1) % 8);
(&m)->set_f261(152 + (i * 1) % 8);
(&m)->set_f262(72 + (i * 1) % 8);
(&m)->set_f263(841332021 + (i * 1) % 8);
(&m)->set_f264(3513197580 + (i * 1) % 8);
(&m)->set_f265(4287184 + (i * 1) % 8);
(&m)->set_f266(16881 + (i * 1) % 8);
(&m)->set_f267(15465 + (i * 1) % 8);
(&m)->set_f268(190 + (i * 1) % 8);
(&m)->set_f269(74 + (i * 1) % 8);
(&m)->set_f270(3961195292 + (i * 1) % 8);
(&m)->set_f271(56035 + (i * 1) % 8);
(&m)->set_f272(12748062 + (i * 1) % 8);
(&m)->set_f273(1044315900 + (i * 1) % 8);
(&m)->set_f274(6317204 + (i * 1) % 8);
(&m)->set_f275(6977877 + (i * 1) % 8);
(&m)->set_f276(561725976 + (i * 1) % 8);
(&m)->set_f277(1268023557 + (i * 1) % 8);
(&m)->set_f278(20825 + (i * 1) % 8);
(&m)->set_f279(39908 + (i * 1) % 8);
(&m)->set_f280(80 + (i * 1) % 8);
(&m)->set_f281(54217 + (i * 1) % 8);
(&m)->set_f282(3496883176 + (i * 1) % 8);
(&m)->set_f283(15096667 + (i * 1) % 8);
(&m)->set_f284(31295 + (i * 1) % 8);
(&m)->set_f285(14317907 + (i * 1) % 8);
(&m)->set_f286(688652975 + (i * 1) % 8);
(&m)->set_f287(13113 + (i * 1) % 8);
(&m)->set_f288(9174537 + (i * 1) % 8);
(&m)->set_f289(137 + (i * 1) % 8);
(&m)->set_f290(34262 + (i * 1) % 8);
(&m)->set_f291(65007 + (i * 1) % 8);
(&m)->set_f292(973146 + (i * 1) % 8);
(&m)->set_f293(17516 + (i * 1) % 8);
(&m)->set_f294(7892888 + (i * 1) % 8);
(&m)->set_f295(137236122 + (i * 1) % 8);
(&m)->set_f296(3308095600 + (i * 1) % 8);
(&m)->set_f297(45 + (i * 1) % 8);
(&m)->set_f298(1534864024 + (i * 1) % 8);
(&m)->set_f299(9103 + (i * 1) % 8);
(&m)->set_f300(207 + (i * 1) % 8);
(&m)->set_f301(3788421019 + (i * 1) % 8);
(&m)->set_f302(11357906 + (i * 1) % 8);
(&m)->set_f303(10576410 + (i * 1) % 8);
(&m)->set_f304(3312482013 + (i * 1) % 8);
(&m)->set_f305(590102904 + (i * 1) % 8);
(&m)->set_f306(2529242150 + (i * 1) % 8);
(&m)->set_f307(34970 + (i * 1) % 8);
(&m)->set_f308(13491042 + (i * 1) % 8);
(&m)->set_f309(181 + (i * 1) % 8);
(&m)->set_f310(16498181 + (i * 1) % 8);
(&m)->set_f311(11271715 + (i * 1) % 8);
(&m)->set_f312(4224807446 + (i * 1) % 8);
(&m)->set_f313(85 + (i * 1) % 8);
(&m)->set_f314(1207089196 + (i * 1) % 8);
(&m)->set_f315(35163 + (i * 1) % 8);
(&m)->set_f316(56218 + (i * 1) % 8);
(&m)->set_f317(87 + (i * 1) % 8);
(&m)->set_f318(190 + (i * 1) % 8);
(&m)->set_f319(3103179762 + (i * 1) % 8);
(&m)->set_f320(4119 + (i * 1) % 8);
(&m)->set_f321(3427052879 + (i * 1) % 8);
(&m)->set_f322(479179356 + (i * 1) % 8);
(&m)->set_f323(219 + (i * 1) % 8);
(&m)->set_f324(2639831692 + (i * 1) % 8);
(&m)->set_f325(8393 + (i * 1) % 8);
(&m)->set_f326(2588764507 + (i * 1) % 8);
(&m)->set_f327(3870 + (i * 1) % 8);
(&m)->set_f328(10924469 + (i * 1) % 8);
(&m)->set_f329(46160 + (i * 1) % 8);
(&m)->set_f330(4051617550 + (i * 1) % 8);
(&m)->set_f331(27262 + (i * 1) % 8);
(&m)->set_f332(2845864492 + (i * 1) % 8);
(&m)->set_f333(201 + (i * 1) % 8);
(&m)->set_f334(28079 + (i * 1) % 8);
(&m)->set_f335(25653 + (i * 1) % 8);
(&m)->set_f336(10004996 + (i * 1) % 8);
(&m)->set_f337(8280 + (i * 1) % 8);
(&m)->set_f338(3605172953 + (i * 1) % 8);
(&m)->set_f339(1699753781 + (i * 1) % 8);
(&m)->set_f340(25330 + (i * 1) % 8);
(&m)->set_f341(1362390790 + (i * 1) % 8);
(&m)->set_f342(173 + (i * 1) % 8);
(&m)->set_f343(3395189995 + (i * 1) % 8);
(&m)->set_f344(3826667 + (i * 1) % 8);
(&m)->set_f345(1833912464 + (i * 1) % 8);
(&m)->set_f346(100 + (i * 1) % 8);
(&m)->set_f347(209 + (i * 1) % 8);
(&m)->set_f348(167 + (i * 1) % 8);
(&m)->set_f349(157 + (i * 1) % 8);
(&m)->set_f350(390794608 + (i * 1) % 8);
(&m)->set_f351(4027391255 + (i * 1) % 8);
(&m)->set_f352(180826209 + (i * 1) % 8);
(&m)->set_f353(2240796 + (i * 1) % 8);
(&m)->set_f354(161 + (i * 1) % 8);
(&m)->set_f355(14520269 + (i * 1) % 8);
(&m)->set_f356(14936635 + (i * 1) % 8);
(&m)->set_f357(192 + (i * 1) % 8);
(&m)->set_f358(77 + (i * 1) % 8);
(&m)->set_f359(39824 + (i * 1) % 8);
(&m)->set_f360(15494732 + (i * 1) % 8);
(&m)->set_f361(63355 + (i * 1) % 8);
(&m)->set_f362(10 + (i * 1) % 8);
(&m)->set_f363(15432613 + (i * 1) % 8);
(&m)->set_f364(3614023 + (i * 1) % 8);
(&m)->set_f365(1130193103 + (i * 1) % 8);
(&m)->set_f366(7474072 + (i * 1) % 8);
(&m)->set_f367(5041977 + (i * 1) % 8);
(&m)->set_f368(13458251 + (i * 1) % 8);
(&m)->set_f369(8313114 + (i * 1) % 8);
(&m)->set_f370(234 + (i * 1) % 8);
(&m)->set_f371(3812410742 + (i * 1) % 8);
(&m)->set_f372(3784 + (i * 1) % 8);
(&m)->set_f373(53352 + (i * 1) % 8);
(&m)->set_f374(205 + (i * 1) % 8);
(&m)->set_f375(52365 + (i * 1) % 8);
(&m)->set_f376(58686 + (i * 1) % 8);
(&m)->set_f377(4227267620 + (i * 1) % 8);
(&m)->set_f378(13278831 + (i * 1) % 8);
(&m)->set_f379(170 + (i * 1) % 8);
(&m)->set_f380(496208199 + (i * 1) % 8);
(&m)->set_f381(54 + (i * 1) % 8);
(&m)->set_f382(2107268640 + (i * 1) % 8);
(&m)->set_f383(4890901 + (i * 1) % 8);
(&m)->set_f384(49424 + (i * 1) % 8);
(&m)->set_f385(2604323999 + (i * 1) % 8);
(&m)->set_f386(42 + (i * 1) % 8);
(&m)->set_f387(23384 + (i * 1) % 8);
(&m)->set_f388(155 + (i * 1) % 8);
(&m)->set_f389(3183000573 + (i * 1) % 8);
(&m)->set_f390(22 + (i * 1) % 8);
(&m)->set_f391(208 + (i * 1) % 8);
(&m)->set_f392(12487723 + (i * 1) % 8);
(&m)->set_f393(56265 + (i * 1) % 8);
(&m)->set_f394(884770090 + (i * 1) % 8);
(&m)->set_f395(4094917362 + (i * 1) % 8);
(&m)->set_f396(102 + (i * 1) % 8);
(&m)->set_f397(4137775035 + (i * 1) % 8);
(&m)->set_f398(1655516623 + (i * 1) % 8);
(&m)->set_f399(3914789 + (i * 1) % 8);
(&m)->set_f400(42 + (i * 1) % 8);


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
