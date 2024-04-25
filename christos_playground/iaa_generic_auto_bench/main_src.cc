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
(&m)->set_f1(5640 + (i * 1) % 8);
(&m)->set_f2(6626548 + (i * 1) % 8);
(&m)->set_f3(26536 + (i * 1) % 8);
(&m)->set_f4(59233 + (i * 1) % 8);
(&m)->set_f5(3347084273 + (i * 1) % 8);
(&m)->set_f6(2188618 + (i * 1) % 8);
(&m)->set_f7(4252843439 + (i * 1) % 8);
(&m)->set_f8(27051 + (i * 1) % 8);
(&m)->set_f9(120 + (i * 1) % 8);
(&m)->set_f10(24573 + (i * 1) % 8);
(&m)->set_f11(201 + (i * 1) % 8);
(&m)->set_f12(5258726 + (i * 1) % 8);
(&m)->set_f13(35 + (i * 1) % 8);
(&m)->set_f14(4047747 + (i * 1) % 8);
(&m)->set_f15(12152487 + (i * 1) % 8);
(&m)->set_f16(3069844 + (i * 1) % 8);
(&m)->set_f17(53832 + (i * 1) % 8);
(&m)->set_f18(13733028 + (i * 1) % 8);
(&m)->set_f19(16271043 + (i * 1) % 8);
(&m)->set_f20(15734046 + (i * 1) % 8);
(&m)->set_f21(1477527403 + (i * 1) % 8);
(&m)->set_f22(1108886 + (i * 1) % 8);
(&m)->set_f23(1231338061 + (i * 1) % 8);
(&m)->set_f24(15319693 + (i * 1) % 8);
(&m)->set_f25(152 + (i * 1) % 8);
(&m)->set_f26(57 + (i * 1) % 8);
(&m)->set_f27(2478630820 + (i * 1) % 8);
(&m)->set_f28(42139 + (i * 1) % 8);
(&m)->set_f29(15992474 + (i * 1) % 8);
(&m)->set_f30(2713283792 + (i * 1) % 8);
(&m)->set_f31(13349 + (i * 1) % 8);
(&m)->set_f32(2682450075 + (i * 1) % 8);
(&m)->set_f33(2175475408 + (i * 1) % 8);
(&m)->set_f34(64468 + (i * 1) % 8);
(&m)->set_f35(210 + (i * 1) % 8);
(&m)->set_f36(58777 + (i * 1) % 8);
(&m)->set_f37(11376876 + (i * 1) % 8);
(&m)->set_f38(2143079881 + (i * 1) % 8);
(&m)->set_f39(2169399 + (i * 1) % 8);
(&m)->set_f40(17577 + (i * 1) % 8);
(&m)->set_f41(24966 + (i * 1) % 8);
(&m)->set_f42(226 + (i * 1) % 8);
(&m)->set_f43(215 + (i * 1) % 8);
(&m)->set_f44(8197631 + (i * 1) % 8);
(&m)->set_f45(92 + (i * 1) % 8);
(&m)->set_f46(58825 + (i * 1) % 8);
(&m)->set_f47(1223437 + (i * 1) % 8);
(&m)->set_f48(46034 + (i * 1) % 8);
(&m)->set_f49(4904 + (i * 1) % 8);
(&m)->set_f50(1606344888 + (i * 1) % 8);
(&m)->set_f51(7784 + (i * 1) % 8);
(&m)->set_f52(25935 + (i * 1) % 8);
(&m)->set_f53(42164 + (i * 1) % 8);
(&m)->set_f54(3947710258 + (i * 1) % 8);
(&m)->set_f55(794377005 + (i * 1) % 8);
(&m)->set_f56(237061 + (i * 1) % 8);
(&m)->set_f57(47512 + (i * 1) % 8);
(&m)->set_f58(131 + (i * 1) % 8);
(&m)->set_f59(198 + (i * 1) % 8);
(&m)->set_f60(3641791 + (i * 1) % 8);
(&m)->set_f61(6243223 + (i * 1) % 8);
(&m)->set_f62(45205 + (i * 1) % 8);
(&m)->set_f63(6512559 + (i * 1) % 8);
(&m)->set_f64(3218926891 + (i * 1) % 8);
(&m)->set_f65(41044 + (i * 1) % 8);
(&m)->set_f66(20772 + (i * 1) % 8);
(&m)->set_f67(3488371 + (i * 1) % 8);
(&m)->set_f68(62133 + (i * 1) % 8);
(&m)->set_f69(45313 + (i * 1) % 8);
(&m)->set_f70(151 + (i * 1) % 8);
(&m)->set_f71(132 + (i * 1) % 8);
(&m)->set_f72(1376512977 + (i * 1) % 8);
(&m)->set_f73(562 + (i * 1) % 8);
(&m)->set_f74(16117437 + (i * 1) % 8);
(&m)->set_f75(29 + (i * 1) % 8);
(&m)->set_f76(12375506 + (i * 1) % 8);
(&m)->set_f77(252 + (i * 1) % 8);
(&m)->set_f78(136 + (i * 1) % 8);
(&m)->set_f79(3105640170 + (i * 1) % 8);
(&m)->set_f80(2698252978 + (i * 1) % 8);
(&m)->set_f81(55 + (i * 1) % 8);
(&m)->set_f82(3447288 + (i * 1) % 8);
(&m)->set_f83(13240499 + (i * 1) % 8);
(&m)->set_f84(153 + (i * 1) % 8);
(&m)->set_f85(486951147 + (i * 1) % 8);
(&m)->set_f86(3597381601 + (i * 1) % 8);
(&m)->set_f87(15843586 + (i * 1) % 8);
(&m)->set_f88(16162166 + (i * 1) % 8);
(&m)->set_f89(1154894501 + (i * 1) % 8);
(&m)->set_f90(184 + (i * 1) % 8);
(&m)->set_f91(13519848 + (i * 1) % 8);
(&m)->set_f92(12461478 + (i * 1) % 8);
(&m)->set_f93(1291543873 + (i * 1) % 8);
(&m)->set_f94(38914 + (i * 1) % 8);
(&m)->set_f95(71 + (i * 1) % 8);
(&m)->set_f96(11166388 + (i * 1) % 8);
(&m)->set_f97(7554767 + (i * 1) % 8);
(&m)->set_f98(37 + (i * 1) % 8);
(&m)->set_f99(8851 + (i * 1) % 8);
(&m)->set_f100(1500669415 + (i * 1) % 8);
(&m)->set_f101(2416369456 + (i * 1) % 8);
(&m)->set_f102(11709332 + (i * 1) % 8);
(&m)->set_f103(340829809 + (i * 1) % 8);
(&m)->set_f104(218476330 + (i * 1) % 8);
(&m)->set_f105(13729276 + (i * 1) % 8);
(&m)->set_f106(52902 + (i * 1) % 8);
(&m)->set_f107(185 + (i * 1) % 8);
(&m)->set_f108(41 + (i * 1) % 8);
(&m)->set_f109(4260462178 + (i * 1) % 8);
(&m)->set_f110(2563904783 + (i * 1) % 8);
(&m)->set_f111(77 + (i * 1) % 8);
(&m)->set_f112(1054188 + (i * 1) % 8);
(&m)->set_f113(18 + (i * 1) % 8);
(&m)->set_f114(103 + (i * 1) % 8);
(&m)->set_f115(244 + (i * 1) % 8);
(&m)->set_f116(56185 + (i * 1) % 8);
(&m)->set_f117(2320166253 + (i * 1) % 8);
(&m)->set_f118(48036 + (i * 1) % 8);
(&m)->set_f119(43337 + (i * 1) % 8);
(&m)->set_f120(231 + (i * 1) % 8);
(&m)->set_f121(15600881 + (i * 1) % 8);
(&m)->set_f122(1316022901 + (i * 1) % 8);
(&m)->set_f123(94 + (i * 1) % 8);
(&m)->set_f124(8923777 + (i * 1) % 8);
(&m)->set_f125(2535293637 + (i * 1) % 8);
(&m)->set_f126(7417 + (i * 1) % 8);
(&m)->set_f127(11815761 + (i * 1) % 8);
(&m)->set_f128(2564791836 + (i * 1) % 8);
(&m)->set_f129(17761 + (i * 1) % 8);
(&m)->set_f130(13584520 + (i * 1) % 8);
(&m)->set_f131(158 + (i * 1) % 8);
(&m)->set_f132(56113 + (i * 1) % 8);
(&m)->set_f133(5 + (i * 1) % 8);
(&m)->set_f134(1362560525 + (i * 1) % 8);
(&m)->set_f135(2516255769 + (i * 1) % 8);
(&m)->set_f136(218 + (i * 1) % 8);
(&m)->set_f137(201 + (i * 1) % 8);
(&m)->set_f138(1355867 + (i * 1) % 8);
(&m)->set_f139(178 + (i * 1) % 8);
(&m)->set_f140(247 + (i * 1) % 8);
(&m)->set_f141(2574025126 + (i * 1) % 8);
(&m)->set_f142(8736400 + (i * 1) % 8);
(&m)->set_f143(9358268 + (i * 1) % 8);
(&m)->set_f144(1965827239 + (i * 1) % 8);
(&m)->set_f145(1129509693 + (i * 1) % 8);
(&m)->set_f146(5303542 + (i * 1) % 8);
(&m)->set_f147(7899186 + (i * 1) % 8);
(&m)->set_f148(58524 + (i * 1) % 8);
(&m)->set_f149(132 + (i * 1) % 8);
(&m)->set_f150(19655185 + (i * 1) % 8);
(&m)->set_f151(11938566 + (i * 1) % 8);
(&m)->set_f152(32430 + (i * 1) % 8);
(&m)->set_f153(46829 + (i * 1) % 8);
(&m)->set_f154(13095017 + (i * 1) % 8);
(&m)->set_f155(243 + (i * 1) % 8);
(&m)->set_f156(92 + (i * 1) % 8);
(&m)->set_f157(11278099 + (i * 1) % 8);
(&m)->set_f158(48 + (i * 1) % 8);
(&m)->set_f159(4270813094 + (i * 1) % 8);
(&m)->set_f160(6766057 + (i * 1) % 8);
(&m)->set_f161(37 + (i * 1) % 8);
(&m)->set_f162(14998125 + (i * 1) % 8);
(&m)->set_f163(1464861 + (i * 1) % 8);
(&m)->set_f164(1945858539 + (i * 1) % 8);
(&m)->set_f165(3216605 + (i * 1) % 8);
(&m)->set_f166(22 + (i * 1) % 8);
(&m)->set_f167(4459125 + (i * 1) % 8);
(&m)->set_f168(63393 + (i * 1) % 8);
(&m)->set_f169(61148 + (i * 1) % 8);
(&m)->set_f170(2472876 + (i * 1) % 8);
(&m)->set_f171(3722102479 + (i * 1) % 8);
(&m)->set_f172(719532473 + (i * 1) % 8);
(&m)->set_f173(3163417475 + (i * 1) % 8);
(&m)->set_f174(660046144 + (i * 1) % 8);
(&m)->set_f175(1042148241 + (i * 1) % 8);
(&m)->set_f176(18697 + (i * 1) % 8);
(&m)->set_f177(16623598 + (i * 1) % 8);
(&m)->set_f178(1361085560 + (i * 1) % 8);
(&m)->set_f179(1549970264 + (i * 1) % 8);
(&m)->set_f180(8875931 + (i * 1) % 8);
(&m)->set_f181(1014452006 + (i * 1) % 8);
(&m)->set_f182(2150321800 + (i * 1) % 8);
(&m)->set_f183(162 + (i * 1) % 8);
(&m)->set_f184(713623303 + (i * 1) % 8);
(&m)->set_f185(229 + (i * 1) % 8);
(&m)->set_f186(1883023113 + (i * 1) % 8);
(&m)->set_f187(42023 + (i * 1) % 8);
(&m)->set_f188(1500795935 + (i * 1) % 8);
(&m)->set_f189(8094818 + (i * 1) % 8);
(&m)->set_f190(17897 + (i * 1) % 8);
(&m)->set_f191(1238094796 + (i * 1) % 8);
(&m)->set_f192(219 + (i * 1) % 8);
(&m)->set_f193(107 + (i * 1) % 8);
(&m)->set_f194(3806861849 + (i * 1) % 8);
(&m)->set_f195(9562 + (i * 1) % 8);
(&m)->set_f196(85 + (i * 1) % 8);
(&m)->set_f197(62 + (i * 1) % 8);
(&m)->set_f198(34662 + (i * 1) % 8);
(&m)->set_f199(9446999 + (i * 1) % 8);
(&m)->set_f200(9137 + (i * 1) % 8);
(&m)->set_f201(0 + (i * 1) % 8);
(&m)->set_f202(47227 + (i * 1) % 8);
(&m)->set_f203(14523172 + (i * 1) % 8);
(&m)->set_f204(58734 + (i * 1) % 8);
(&m)->set_f205(12060566 + (i * 1) % 8);
(&m)->set_f206(5315480 + (i * 1) % 8);
(&m)->set_f207(35 + (i * 1) % 8);
(&m)->set_f208(1438696833 + (i * 1) % 8);
(&m)->set_f209(358992507 + (i * 1) % 8);
(&m)->set_f210(67 + (i * 1) % 8);
(&m)->set_f211(32 + (i * 1) % 8);
(&m)->set_f212(46498 + (i * 1) % 8);
(&m)->set_f213(37854 + (i * 1) % 8);
(&m)->set_f214(16361494 + (i * 1) % 8);
(&m)->set_f215(237 + (i * 1) % 8);
(&m)->set_f216(1870050 + (i * 1) % 8);
(&m)->set_f217(16 + (i * 1) % 8);
(&m)->set_f218(64437 + (i * 1) % 8);
(&m)->set_f219(2777439608 + (i * 1) % 8);
(&m)->set_f220(508871822 + (i * 1) % 8);
(&m)->set_f221(2310774345 + (i * 1) % 8);
(&m)->set_f222(2033652891 + (i * 1) % 8);
(&m)->set_f223(56 + (i * 1) % 8);
(&m)->set_f224(136 + (i * 1) % 8);
(&m)->set_f225(1155806449 + (i * 1) % 8);
(&m)->set_f226(2780530536 + (i * 1) % 8);
(&m)->set_f227(15600666 + (i * 1) % 8);
(&m)->set_f228(8605438 + (i * 1) % 8);
(&m)->set_f229(1553391340 + (i * 1) % 8);
(&m)->set_f230(1449859300 + (i * 1) % 8);
(&m)->set_f231(130 + (i * 1) % 8);
(&m)->set_f232(154 + (i * 1) % 8);
(&m)->set_f233(14091680 + (i * 1) % 8);
(&m)->set_f234(526573024 + (i * 1) % 8);
(&m)->set_f235(12839666 + (i * 1) % 8);
(&m)->set_f236(59 + (i * 1) % 8);
(&m)->set_f237(254 + (i * 1) % 8);
(&m)->set_f238(9142182 + (i * 1) % 8);
(&m)->set_f239(20339 + (i * 1) % 8);
(&m)->set_f240(1027613 + (i * 1) % 8);
(&m)->set_f241(3858244296 + (i * 1) % 8);
(&m)->set_f242(233 + (i * 1) % 8);
(&m)->set_f243(534747475 + (i * 1) % 8);
(&m)->set_f244(22051 + (i * 1) % 8);
(&m)->set_f245(37294 + (i * 1) % 8);
(&m)->set_f246(99 + (i * 1) % 8);
(&m)->set_f247(4167503185 + (i * 1) % 8);
(&m)->set_f248(628626159 + (i * 1) % 8);
(&m)->set_f249(9625606 + (i * 1) % 8);
(&m)->set_f250(57691 + (i * 1) % 8);
(&m)->set_f251(211 + (i * 1) % 8);
(&m)->set_f252(29 + (i * 1) % 8);
(&m)->set_f253(205 + (i * 1) % 8);
(&m)->set_f254(7098736 + (i * 1) % 8);
(&m)->set_f255(136 + (i * 1) % 8);
(&m)->set_f256(60967 + (i * 1) % 8);
(&m)->set_f257(1149021291 + (i * 1) % 8);
(&m)->set_f258(411242237 + (i * 1) % 8);
(&m)->set_f259(2749100310 + (i * 1) % 8);
(&m)->set_f260(41076 + (i * 1) % 8);
(&m)->set_f261(2938132 + (i * 1) % 8);
(&m)->set_f262(1671948977 + (i * 1) % 8);
(&m)->set_f263(26049 + (i * 1) % 8);
(&m)->set_f264(4100255138 + (i * 1) % 8);
(&m)->set_f265(1106711878 + (i * 1) % 8);
(&m)->set_f266(11522677 + (i * 1) % 8);
(&m)->set_f267(2137855290 + (i * 1) % 8);
(&m)->set_f268(85 + (i * 1) % 8);
(&m)->set_f269(254 + (i * 1) % 8);
(&m)->set_f270(5773 + (i * 1) % 8);
(&m)->set_f271(48280 + (i * 1) % 8);
(&m)->set_f272(8438906 + (i * 1) % 8);
(&m)->set_f273(937617672 + (i * 1) % 8);
(&m)->set_f274(190 + (i * 1) % 8);
(&m)->set_f275(74 + (i * 1) % 8);
(&m)->set_f276(16470 + (i * 1) % 8);
(&m)->set_f277(2390713244 + (i * 1) % 8);
(&m)->set_f278(12810 + (i * 1) % 8);
(&m)->set_f279(251 + (i * 1) % 8);
(&m)->set_f280(449087228 + (i * 1) % 8);
(&m)->set_f281(13 + (i * 1) % 8);
(&m)->set_f282(4805112 + (i * 1) % 8);
(&m)->set_f283(7240706 + (i * 1) % 8);
(&m)->set_f284(0 + (i * 1) % 8);
(&m)->set_f285(2953716 + (i * 1) % 8);
(&m)->set_f286(25 + (i * 1) % 8);
(&m)->set_f287(894407894 + (i * 1) % 8);
(&m)->set_f288(252 + (i * 1) % 8);
(&m)->set_f289(7503543 + (i * 1) % 8);
(&m)->set_f290(7643235 + (i * 1) % 8);
(&m)->set_f291(31989 + (i * 1) % 8);
(&m)->set_f292(160 + (i * 1) % 8);
(&m)->set_f293(7422618 + (i * 1) % 8);
(&m)->set_f294(4133668 + (i * 1) % 8);
(&m)->set_f295(48 + (i * 1) % 8);
(&m)->set_f296(13331 + (i * 1) % 8);
(&m)->set_f297(3851104103 + (i * 1) % 8);
(&m)->set_f298(4945853 + (i * 1) % 8);
(&m)->set_f299(1867829 + (i * 1) % 8);
(&m)->set_f300(6665347 + (i * 1) % 8);
(&m)->set_f301(2450493997 + (i * 1) % 8);
(&m)->set_f302(153 + (i * 1) % 8);
(&m)->set_f303(41 + (i * 1) % 8);
(&m)->set_f304(15 + (i * 1) % 8);
(&m)->set_f305(9488627 + (i * 1) % 8);
(&m)->set_f306(1256280955 + (i * 1) % 8);
(&m)->set_f307(1440725208 + (i * 1) % 8);
(&m)->set_f308(2388780064 + (i * 1) % 8);
(&m)->set_f309(9920683 + (i * 1) % 8);
(&m)->set_f310(161 + (i * 1) % 8);
(&m)->set_f311(14949170 + (i * 1) % 8);
(&m)->set_f312(5096926 + (i * 1) % 8);
(&m)->set_f313(220 + (i * 1) % 8);
(&m)->set_f314(20383 + (i * 1) % 8);
(&m)->set_f315(2462672032 + (i * 1) % 8);
(&m)->set_f316(2452900217 + (i * 1) % 8);
(&m)->set_f317(10941299 + (i * 1) % 8);
(&m)->set_f318(91 + (i * 1) % 8);
(&m)->set_f319(10802372 + (i * 1) % 8);
(&m)->set_f320(9299 + (i * 1) % 8);
(&m)->set_f321(5548184 + (i * 1) % 8);
(&m)->set_f322(2173241962 + (i * 1) % 8);
(&m)->set_f323(7574185 + (i * 1) % 8);
(&m)->set_f324(710872340 + (i * 1) % 8);
(&m)->set_f325(2644922404 + (i * 1) % 8);
(&m)->set_f326(153 + (i * 1) % 8);
(&m)->set_f327(1210 + (i * 1) % 8);
(&m)->set_f328(14587455 + (i * 1) % 8);
(&m)->set_f329(1501206649 + (i * 1) % 8);
(&m)->set_f330(1196687 + (i * 1) % 8);
(&m)->set_f331(14327535 + (i * 1) % 8);
(&m)->set_f332(117 + (i * 1) % 8);
(&m)->set_f333(860482 + (i * 1) % 8);
(&m)->set_f334(12905870 + (i * 1) % 8);
(&m)->set_f335(6760639 + (i * 1) % 8);
(&m)->set_f336(15910 + (i * 1) % 8);
(&m)->set_f337(244 + (i * 1) % 8);
(&m)->set_f338(219 + (i * 1) % 8);
(&m)->set_f339(11848236 + (i * 1) % 8);
(&m)->set_f340(218 + (i * 1) % 8);
(&m)->set_f341(78 + (i * 1) % 8);
(&m)->set_f342(62 + (i * 1) % 8);
(&m)->set_f343(999789 + (i * 1) % 8);
(&m)->set_f344(82 + (i * 1) % 8);
(&m)->set_f345(3060737847 + (i * 1) % 8);
(&m)->set_f346(16 + (i * 1) % 8);
(&m)->set_f347(28278 + (i * 1) % 8);
(&m)->set_f348(51 + (i * 1) % 8);
(&m)->set_f349(47252 + (i * 1) % 8);
(&m)->set_f350(46169 + (i * 1) % 8);
(&m)->set_f351(10905406 + (i * 1) % 8);
(&m)->set_f352(152 + (i * 1) % 8);
(&m)->set_f353(9093429 + (i * 1) % 8);
(&m)->set_f354(13999822 + (i * 1) % 8);
(&m)->set_f355(113 + (i * 1) % 8);
(&m)->set_f356(3297578996 + (i * 1) % 8);
(&m)->set_f357(52347 + (i * 1) % 8);
(&m)->set_f358(216 + (i * 1) % 8);
(&m)->set_f359(1453338629 + (i * 1) % 8);
(&m)->set_f360(11796493 + (i * 1) % 8);
(&m)->set_f361(81 + (i * 1) % 8);
(&m)->set_f362(3222503193 + (i * 1) % 8);
(&m)->set_f363(41782 + (i * 1) % 8);
(&m)->set_f364(9800276 + (i * 1) % 8);
(&m)->set_f365(48027 + (i * 1) % 8);
(&m)->set_f366(278357167 + (i * 1) % 8);
(&m)->set_f367(41294 + (i * 1) % 8);
(&m)->set_f368(2421138247 + (i * 1) % 8);
(&m)->set_f369(57316 + (i * 1) % 8);
(&m)->set_f370(57961 + (i * 1) % 8);
(&m)->set_f371(364404 + (i * 1) % 8);
(&m)->set_f372(2695653 + (i * 1) % 8);
(&m)->set_f373(9921 + (i * 1) % 8);
(&m)->set_f374(194 + (i * 1) % 8);
(&m)->set_f375(49034 + (i * 1) % 8);
(&m)->set_f376(13574 + (i * 1) % 8);
(&m)->set_f377(128 + (i * 1) % 8);
(&m)->set_f378(12 + (i * 1) % 8);
(&m)->set_f379(2917859342 + (i * 1) % 8);
(&m)->set_f380(11655324 + (i * 1) % 8);
(&m)->set_f381(5235505 + (i * 1) % 8);
(&m)->set_f382(170 + (i * 1) % 8);
(&m)->set_f383(9929 + (i * 1) % 8);
(&m)->set_f384(8 + (i * 1) % 8);
(&m)->set_f385(10218879 + (i * 1) % 8);
(&m)->set_f386(288185382 + (i * 1) % 8);
(&m)->set_f387(196 + (i * 1) % 8);
(&m)->set_f388(2248338736 + (i * 1) % 8);
(&m)->set_f389(2413925551 + (i * 1) % 8);
(&m)->set_f390(2748829633 + (i * 1) % 8);
(&m)->set_f391(6074261 + (i * 1) % 8);
(&m)->set_f392(46558 + (i * 1) % 8);
(&m)->set_f393(19100 + (i * 1) % 8);
(&m)->set_f394(129 + (i * 1) % 8);
(&m)->set_f395(11589014 + (i * 1) % 8);
(&m)->set_f396(26882 + (i * 1) % 8);
(&m)->set_f397(1843 + (i * 1) % 8);
(&m)->set_f398(15305699 + (i * 1) % 8);
(&m)->set_f399(1006979 + (i * 1) % 8);
(&m)->set_f400(19940 + (i * 1) % 8);


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
