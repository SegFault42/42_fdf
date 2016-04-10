#include "./fdf.h"

#define snow 0xfffafa
#define ghost white 0xf8f8ff
#define ghostwhite 0xf8f8ff
#define white smoke 0xf5f5f5
#define whitesmoke 0xf5f5f5
#define gainsboro 0xdcdcdc
#define floral white 0xfffaf0
#define floralwhite 0xfffaf0
#define old lace 0xfdf5e6
#define oldlace 0xfdf5e6
#define linen 0xfaf0e6
#define antique white 0xfaebd7
#define antiquewhite 0xfaebd7
#define papaya whip 0xffefd5
#define papayawhip 0xffefd5
#define blanched almond 0xffebcd
#define blanchedalmond 0xffebcd
#define bisque 0xffe4c4
#define peach puff 0xffdab9
#define peachpuff 0xffdab9
#define navajo white 0xffdead
#define navajowhite 0xffdead
#define moccasin 0xffe4b5
#define cornsilk 0xfff8dc
#define ivory 0xfffff0
#define lemon chiffon 0xfffacd
#define lemonchiffon 0xfffacd
#define seashell 0xfff5ee
#define honeydew 0xf0fff0
#define mint cream 0xf5fffa
#define mintcream 0xf5fffa
#define azure 0xf0ffff
#define alice blue 0xf0f8ff
#define aliceblue 0xf0f8ff
#define lavender 0xe6e6fa
#define lavender blush 0xfff0f5
#define lavenderblush 0xfff0f5
#define misty rose 0xffe4e1
#define mistyrose 0xffe4e1
#define white 0xffffff
#define black 0x0
#define dark slate 0x2f4f4f
#define darkslategray 0x2f4f4f
#define dark slate 0x2f4f4f
#define darkslategrey 0x2f4f4f
#define dim gray 0x696969
#define dimgray 0x696969
#define dim grey 0x696969
#define dimgrey 0x696969
#define slate gray 0x708090
#define slategray 0x708090
#define slate grey 0x708090
#define slategrey 0x708090
#define light slate 0x778899
#define lightslategray 0x778899
#define light slate 0x778899
#define lightslategrey 0x778899
#define gray 0xbebebe
#define grey 0xbebebe
#define light grey 0xd3d3d3
#define lightgrey 0xd3d3d3
#define light gray 0xd3d3d3
#define lightgray 0xd3d3d3
#define midnight blue 0x191970
#define midnightblue 0x191970
#define navy 0x80
#define navy blue 0x80
#define navyblue 0x80
#define cornflower blue 0x6495ed
#define cornflowerblue 0x6495ed
#define dark slate 0x483d8b
#define darkslateblue 0x483d8b
#define slate blue 0x6a5acd
#define slateblue 0x6a5acd
#define medium slate 0x7b68ee
#define mediumslateblue 0x7b68ee
#define light slate 0x8470ff
#define lightslateblue 0x8470ff
#define medium blue 0xcd
#define mediumblue 0xcd
#define royal blue 0x4169e1
#define royalblue 0x4169e1
#define blue 0xff
#define dodger blue 0x1e90ff
#define dodgerblue 0x1e90ff
#define deep sky 0xbfff
#define deepskyblue 0xbfff
#define sky blue 0x87ceeb
#define skyblue 0x87ceeb
#define light sky 0x87cefa
#define lightskyblue 0x87cefa
#define steel blue 0x4682b4
#define steelblue 0x4682b4
#define light steel 0xb0c4de
#define lightsteelblue 0xb0c4de
#define light blue 0xadd8e6
#define lightblue 0xadd8e6
#define powder blue 0xb0e0e6
#define powderblue 0xb0e0e6
#define pale turquoise 0xafeeee
#define paleturquoise 0xafeeee
#define dark turquoise 0xced1
#define darkturquoise 0xced1
#define medium turquoise 0x48d1cc
#define mediumturquoise 0x48d1cc
#define turquoise 0x40e0d0
#define cyan 0xffff
#define light cyan 0xe0ffff
#define lightcyan 0xe0ffff
#define cadet blue 0x5f9ea0
#define cadetblue 0x5f9ea0
#define medium aquamarine 0x66cdaa
#define mediumaquamarine 0x66cdaa
#define aquamarine 0x7fffd4
#define dark green 0x6400
#define darkgreen 0x6400
#define dark olive 0x556b2f
#define darkolivegreen 0x556b2f
#define dark sea 0x8fbc8f
#define darkseagreen 0x8fbc8f
#define sea green 0x2e8b57
#define seagreen 0x2e8b57
#define medium sea 0x3cb371
#define mediumseagreen 0x3cb371
#define light sea 0x20b2aa
#define lightseagreen 0x20b2aa
#define pale green 0x98fb98
#define palegreen 0x98fb98
#define spring green 0xff7f
#define springgreen 0xff7f
#define lawn green 0x7cfc00
#define lawngreen 0x7cfc00
#define green 0xff00
#define chartreuse 0x7fff00
#define medium spring 0xfa9a
#define mediumspringgreen 0xfa9a
#define green yellow 0xadff2f
#define greenyellow 0xadff2f
#define lime green 0x32cd32
#define limegreen 0x32cd32
#define yellow green 0x9acd32
#define yellowgreen 0x9acd32
#define forest green 0x228b22
#define forestgreen 0x228b22
#define olive drab 0x6b8e23
#define olivedrab 0x6b8e23
#define dark khaki 0xbdb76b
#define darkkhaki 0xbdb76b
#define khaki 0xf0e68c
#define pale goldenrod 0xeee8aa
#define palegoldenrod 0xeee8aa
#define light goldenrod 0xfafad2
#define lightgoldenrodyellow 0xfafad2
#define light yellow 0xffffe0
#define lightyellow 0xffffe0
#define yellow 0xffff00
#define gold 0xffd700
#define light goldenrod 0xeedd82
#define lightgoldenrod 0xeedd82
#define goldenrod 0xdaa520
#define dark goldenrod 0xb8860b
#define darkgoldenrod 0xb8860b
#define rosy brown 0xbc8f8f
#define rosybrown 0xbc8f8f
#define indian red 0xcd5c5c
#define indianred 0xcd5c5c
#define saddle brown 0x8b4513
#define saddlebrown 0x8b4513
#define sienna 0xa0522d
#define peru 0xcd853f
#define burlywood 0xdeb887
#define beige 0xf5f5dc
#define wheat 0xf5deb3
#define sandy brown 0xf4a460
#define sandybrown 0xf4a460
#define tan 0xd2b48c
#define chocolate 0xd2691e
#define firebrick 0xb22222
#define brown 0xa52a2a
#define dark salmon 0xe9967a
#define darksalmon 0xe9967a
#define salmon 0xfa8072
#define light salmon 0xffa07a
#define lightsalmon 0xffa07a
#define orange 0xffa500
#define dark orange 0xff8c00
#define darkorange 0xff8c00
#define coral 0xff7f50
#define light coral 0xf08080
#define lightcoral 0xf08080
#define tomato 0xff6347
#define orange red 0xff4500
#define orangered 0xff4500
#define red 0xff0000
#define hot pink 0xff69b4
#define hotpink 0xff69b4
#define deep pink 0xff1493
#define deeppink 0xff1493
#define pink 0xffc0cb
#define light pink 0xffb6c1
#define lightpink 0xffb6c1
#define pale violet 0xdb7093
#define palevioletred 0xdb7093
#define maroon 0xb03060
#define medium violet 0xc71585
#define mediumvioletred 0xc71585
#define violet red 0xd02090
#define violetred 0xd02090
#define magenta 0xff00ff
#define violet 0xee82ee
#define plum 0xdda0dd
#define orchid 0xda70d6
#define medium orchid 0xba55d3
#define mediumorchid 0xba55d3
#define dark orchid 0x9932cc
#define darkorchid 0x9932cc
#define dark violet 0x9400d3
#define darkviolet 0x9400d3
#define blue violet 0x8a2be2
#define blueviolet 0x8a2be2
#define purple 0xa020f0
#define medium purple 0x9370db
#define mediumpurple 0x9370db
#define thistle 0xd8bfd8
#define snow1 0xfffafa
#define snow2 0xeee9e9
#define snow3 0xcdc9c9
#define snow4 0x8b8989
#define seashell1 0xfff5ee
#define seashell2 0xeee5de
#define seashell3 0xcdc5bf
#define seashell4 0x8b8682
#define antiquewhite1 0xffefdb
#define antiquewhite2 0xeedfcc
#define antiquewhite3 0xcdc0b0
#define antiquewhite4 0x8b8378
#define bisque1 0xffe4c4
#define bisque2 0xeed5b7
#define bisque3 0xcdb79e
#define bisque4 0x8b7d6b
#define peachpuff1 0xffdab9
#define peachpuff2 0xeecbad
#define peachpuff3 0xcdaf95
#define peachpuff4 0x8b7765
#define navajowhite1 0xffdead
#define navajowhite2 0xeecfa1
#define navajowhite3 0xcdb38b
#define navajowhite4 0x8b795e
#define lemonchiffon1 0xfffacd
#define lemonchiffon2 0xeee9bf
#define lemonchiffon3 0xcdc9a5
#define lemonchiffon4 0x8b8970
#define cornsilk1 0xfff8dc
#define cornsilk2 0xeee8cd
#define cornsilk3 0xcdc8b1
#define cornsilk4 0x8b8878
#define ivory1 0xfffff0
#define ivory2 0xeeeee0
#define ivory3 0xcdcdc1
#define ivory4 0x8b8b83
#define honeydew1 0xf0fff0
#define honeydew2 0xe0eee0
#define honeydew3 0xc1cdc1
#define honeydew4 0x838b83
#define lavenderblush1 0xfff0f5
#define lavenderblush2 0xeee0e5
#define lavenderblush3 0xcdc1c5
#define lavenderblush4 0x8b8386
#define mistyrose1 0xffe4e1
#define mistyrose2 0xeed5d2
#define mistyrose3 0xcdb7b5
#define mistyrose4 0x8b7d7b
#define azure1 0xf0ffff
#define azure2 0xe0eeee
#define azure3 0xc1cdcd
#define azure4 0x838b8b
#define slateblue1 0x836fff
#define slateblue2 0x7a67ee
#define slateblue3 0x6959cd
#define slateblue4 0x473c8b
#define royalblue1 0x4876ff
#define royalblue2 0x436eee
#define royalblue3 0x3a5fcd
#define royalblue4 0x27408b
#define blue1 0xff
#define blue2 0xee
#define blue3 0xcd
#define blue4 0x8b
#define dodgerblue1 0x1e90ff
#define dodgerblue2 0x1c86ee
#define dodgerblue3 0x1874cd
#define dodgerblue4 0x104e8b
#define steelblue1 0x63b8ff
#define steelblue2 0x5cacee
#define steelblue3 0x4f94cd
#define steelblue4 0x36648b
#define deepskyblue1 0xbfff
#define deepskyblue2 0xb2ee
#define deepskyblue3 0x9acd
#define deepskyblue4 0x688b
#define skyblue1 0x87ceff
#define skyblue2 0x7ec0ee
#define skyblue3 0x6ca6cd
#define skyblue4 0x4a708b
#define lightskyblue1 0xb0e2ff
#define lightskyblue2 0xa4d3ee
#define lightskyblue3 0x8db6cd
#define lightskyblue4 0x607b8b
#define slategray1 0xc6e2ff
#define slategray2 0xb9d3ee
#define slategray3 0x9fb6cd
#define slategray4 0x6c7b8b
#define lightsteelblue1 0xcae1ff
#define lightsteelblue2 0xbcd2ee
#define lightsteelblue3 0xa2b5cd
#define lightsteelblue4 0x6e7b8b
#define lightblue1 0xbfefff
#define lightblue2 0xb2dfee
#define lightblue3 0x9ac0cd
#define lightblue4 0x68838b
#define lightcyan1 0xe0ffff
#define lightcyan2 0xd1eeee
#define lightcyan3 0xb4cdcd
#define lightcyan4 0x7a8b8b
#define paleturquoise1 0xbbffff
#define paleturquoise2 0xaeeeee
#define paleturquoise3 0x96cdcd
#define paleturquoise4 0x668b8b
#define cadetblue1 0x98f5ff
#define cadetblue2 0x8ee5ee
#define cadetblue3 0x7ac5cd
#define cadetblue4 0x53868b
#define turquoise1 0xf5ff
#define turquoise2 0xe5ee
#define turquoise3 0xc5cd
#define turquoise4 0x868b
#define cyan1 0xffff
#define cyan2 0xeeee
#define cyan3 0xcdcd
#define cyan4 0x8b8b
#define darkslategray1 0x97ffff
#define darkslategray2 0x8deeee
#define darkslategray3 0x79cdcd
#define darkslategray4 0x528b8b
#define aquamarine1 0x7fffd4
#define aquamarine2 0x76eec6
#define aquamarine3 0x66cdaa
#define aquamarine4 0x458b74
#define darkseagreen1 0xc1ffc1
#define darkseagreen2 0xb4eeb4
#define darkseagreen3 0x9bcd9b
#define darkseagreen4 0x698b69
#define seagreen1 0x54ff9f
#define seagreen2 0x4eee94
#define seagreen3 0x43cd80
#define seagreen4 0x2e8b57
#define palegreen1 0x9aff9a
#define palegreen2 0x90ee90
#define palegreen3 0x7ccd7c
#define palegreen4 0x548b54
#define springgreen1 0xff7f
#define springgreen2 0xee76
#define springgreen3 0xcd66
#define springgreen4 0x8b45
#define green1 0xff00
#define green2 0xee00
#define green3 0xcd00
#define green4 0x8b00
#define chartreuse1 0x7fff00
#define chartreuse2 0x76ee00
#define chartreuse3 0x66cd00
#define chartreuse4 0x458b00
#define olivedrab1 0xc0ff3e
#define olivedrab2 0xb3ee3a
#define olivedrab3 0x9acd32
#define olivedrab4 0x698b22
#define darkolivegreen1 0xcaff70
#define darkolivegreen2 0xbcee68
#define darkolivegreen3 0xa2cd5a
#define darkolivegreen4 0x6e8b3d
#define khaki1 0xfff68f
#define khaki2 0xeee685
#define khaki3 0xcdc673
#define khaki4 0x8b864e
#define lightgoldenrod1 0xffec8b
#define lightgoldenrod2 0xeedc82
#define lightgoldenrod3 0xcdbe70
#define lightgoldenrod4 0x8b814c
#define lightyellow1 0xffffe0
#define lightyellow2 0xeeeed1
#define lightyellow3 0xcdcdb4
#define lightyellow4 0x8b8b7a
#define yellow1 0xffff00
#define yellow2 0xeeee00
#define yellow3 0xcdcd00
#define yellow4 0x8b8b00
#define gold1 0xffd700
#define gold2 0xeec900
#define gold3 0xcdad00
#define gold4 0x8b7500
#define goldenrod1 0xffc125
#define goldenrod2 0xeeb422
#define goldenrod3 0xcd9b1d
#define goldenrod4 0x8b6914
#define darkgoldenrod1 0xffb90f
#define darkgoldenrod2 0xeead0e
#define darkgoldenrod3 0xcd950c
#define darkgoldenrod4 0x8b6508
#define rosybrown1 0xffc1c1
#define rosybrown2 0xeeb4b4
#define rosybrown3 0xcd9b9b
#define rosybrown4 0x8b6969
#define indianred1 0xff6a6a
#define indianred2 0xee6363
#define indianred3 0xcd5555
#define indianred4 0x8b3a3a
#define sienna1 0xff8247
#define sienna2 0xee7942
#define sienna3 0xcd6839
#define sienna4 0x8b4726
#define burlywood1 0xffd39b
#define burlywood2 0xeec591
#define burlywood3 0xcdaa7d
#define burlywood4 0x8b7355
#define wheat1 0xffe7ba
#define wheat2 0xeed8ae
#define wheat3 0xcdba96
#define wheat4 0x8b7e66
#define tan1 0xffa54f
#define tan2 0xee9a49
#define tan3 0xcd853f
#define tan4 0x8b5a2b
#define chocolate1 0xff7f24
#define chocolate2 0xee7621
#define chocolate3 0xcd661d
#define chocolate4 0x8b4513
#define firebrick1 0xff3030
#define firebrick2 0xee2c2c
#define firebrick3 0xcd2626
#define firebrick4 0x8b1a1a
#define brown1 0xff4040
#define brown2 0xee3b3b
#define brown3 0xcd3333
#define brown4 0x8b2323
#define salmon1 0xff8c69
#define salmon2 0xee8262
#define salmon3 0xcd7054
#define salmon4 0x8b4c39
#define lightsalmon1 0xffa07a
#define lightsalmon2 0xee9572
#define lightsalmon3 0xcd8162
#define lightsalmon4 0x8b5742
#define orange1 0xffa500
#define orange2 0xee9a00
#define orange3 0xcd8500
#define orange4 0x8b5a00
#define darkorange1 0xff7f00
#define darkorange2 0xee7600
#define darkorange3 0xcd6600
#define darkorange4 0x8b4500
#define coral1 0xff7256
#define coral2 0xee6a50
#define coral3 0xcd5b45
#define coral4 0x8b3e2f
#define tomato1 0xff6347
#define tomato2 0xee5c42
#define tomato3 0xcd4f39
#define tomato4 0x8b3626
#define orangered1 0xff4500
#define orangered2 0xee4000
#define orangered3 0xcd3700
#define orangered4 0x8b2500
#define red1 0xff0000
#define red2 0xee0000
#define red3 0xcd0000
#define red4 0x8b0000
#define deeppink1 0xff1493
#define deeppink2 0xee1289
#define deeppink3 0xcd1076
#define deeppink4 0x8b0a50
#define hotpink1 0xff6eb4
#define hotpink2 0xee6aa7
#define hotpink3 0xcd6090
#define hotpink4 0x8b3a62
#define pink1 0xffb5c5
#define pink2 0xeea9b8
#define pink3 0xcd919e
#define pink4 0x8b636c
#define lightpink1 0xffaeb9
#define lightpink2 0xeea2ad
#define lightpink3 0xcd8c95
#define lightpink4 0x8b5f65
#define palevioletred1 0xff82ab
#define palevioletred2 0xee799f
#define palevioletred3 0xcd6889
#define palevioletred4 0x8b475d
#define maroon1 0xff34b3
#define maroon2 0xee30a7
#define maroon3 0xcd2990
#define maroon4 0x8b1c62
#define violetred1 0xff3e96
#define violetred2 0xee3a8c
#define violetred3 0xcd3278
#define violetred4 0x8b2252
#define magenta1 0xff00ff
#define magenta2 0xee00ee
#define magenta3 0xcd00cd
#define magenta4 0x8b008b
#define orchid1 0xff83fa
#define orchid2 0xee7ae9
#define orchid3 0xcd69c9
#define orchid4 0x8b4789
#define plum1 0xffbbff
#define plum2 0xeeaeee
#define plum3 0xcd96cd
#define plum4 0x8b668b
#define mediumorchid1 0xe066ff
#define mediumorchid2 0xd15fee
#define mediumorchid3 0xb452cd
#define mediumorchid4 0x7a378b
#define darkorchid1 0xbf3eff
#define darkorchid2 0xb23aee
#define darkorchid3 0x9a32cd
#define darkorchid4 0x68228b
#define purple1 0x9b30ff
#define purple2 0x912cee
#define purple3 0x7d26cd
#define purple4 0x551a8b
#define mediumpurple1 0xab82ff
#define mediumpurple2 0x9f79ee
#define mediumpurple3 0x8968cd
#define mediumpurple4 0x5d478b
#define thistle1 0xffe1ff
#define thistle2 0xeed2ee
#define thistle3 0xcdb5cd
#define thistle4 0x8b7b8b
#define gray0 0x0
#define grey0 0x0
#define gray1 0x30303
#define grey1 0x30303
#define gray2 0x50505
#define grey2 0x50505
#define gray3 0x80808
#define grey3 0x80808
#define gray4 0xa0a0a
#define grey4 0xa0a0a
#define gray5 0xd0d0d
#define grey5 0xd0d0d
#define gray6 0xf0f0f
#define grey6 0xf0f0f
#define gray7 0x121212
#define grey7 0x121212
#define gray8 0x141414
#define grey8 0x141414
#define gray9 0x171717
#define grey9 0x171717
#define gray10 0x1a1a1a
#define grey10 0x1a1a1a
#define gray11 0x1c1c1c
#define grey11 0x1c1c1c
#define gray12 0x1f1f1f
#define grey12 0x1f1f1f
#define gray13 0x212121
#define grey13 0x212121
#define gray14 0x242424
#define grey14 0x242424
#define gray15 0x262626
#define grey15 0x262626
#define gray16 0x292929
#define grey16 0x292929
#define gray17 0x2b2b2b
#define grey17 0x2b2b2b
#define gray18 0x2e2e2e
#define grey18 0x2e2e2e
#define gray19 0x303030
#define grey19 0x303030
#define gray20 0x333333
#define grey20 0x333333
#define gray21 0x363636
#define grey21 0x363636
#define gray22 0x383838
#define grey22 0x383838
#define gray23 0x3b3b3b
#define grey23 0x3b3b3b
#define gray24 0x3d3d3d
#define grey24 0x3d3d3d
#define gray25 0x404040
#define grey25 0x404040
#define gray26 0x424242
#define grey26 0x424242
#define gray27 0x454545
#define grey27 0x454545
#define gray28 0x474747
#define grey28 0x474747
#define gray29 0x4a4a4a
#define grey29 0x4a4a4a
#define gray30 0x4d4d4d
#define grey30 0x4d4d4d
#define gray31 0x4f4f4f
#define grey31 0x4f4f4f
#define gray32 0x525252
#define grey32 0x525252
#define gray33 0x545454
#define grey33 0x545454
#define gray34 0x575757
#define grey34 0x575757
#define gray35 0x595959
#define grey35 0x595959
#define gray36 0x5c5c5c
#define grey36 0x5c5c5c
#define gray37 0x5e5e5e
#define grey37 0x5e5e5e
#define gray38 0x616161
#define grey38 0x616161
#define gray39 0x636363
#define grey39 0x636363
#define gray40 0x666666
#define grey40 0x666666
#define gray41 0x696969
#define grey41 0x696969
#define gray42 0x6b6b6b
#define grey42 0x6b6b6b
#define gray43 0x6e6e6e
#define grey43 0x6e6e6e
#define gray44 0x707070
#define grey44 0x707070
#define gray45 0x737373
#define grey45 0x737373
#define gray46 0x757575
#define grey46 0x757575
#define gray47 0x787878
#define grey47 0x787878
#define gray48 0x7a7a7a
#define grey48 0x7a7a7a
#define gray49 0x7d7d7d
#define grey49 0x7d7d7d
#define gray50 0x7f7f7f
#define grey50 0x7f7f7f
#define gray51 0x828282
#define grey51 0x828282
#define gray52 0x858585
#define grey52 0x858585
#define gray53 0x878787
#define grey53 0x878787
#define gray54 0x8a8a8a
#define grey54 0x8a8a8a
#define gray55 0x8c8c8c
#define grey55 0x8c8c8c
#define gray56 0x8f8f8f
#define grey56 0x8f8f8f
#define gray57 0x919191
#define grey57 0x919191
#define gray58 0x949494
#define grey58 0x949494
#define gray59 0x969696
#define grey59 0x969696
#define gray60 0x999999
#define grey60 0x999999
#define gray61 0x9c9c9c
#define grey61 0x9c9c9c
#define gray62 0x9e9e9e
#define grey62 0x9e9e9e
#define gray63 0xa1a1a1
#define grey63 0xa1a1a1
#define gray64 0xa3a3a3
#define grey64 0xa3a3a3
#define gray65 0xa6a6a6
#define grey65 0xa6a6a6
#define gray66 0xa8a8a8
#define grey66 0xa8a8a8
#define gray67 0xababab
#define grey67 0xababab
#define gray68 0xadadad
#define grey68 0xadadad
#define gray69 0xb0b0b0
#define grey69 0xb0b0b0
#define gray70 0xb3b3b3
#define grey70 0xb3b3b3
#define gray71 0xb5b5b5
#define grey71 0xb5b5b5
#define gray72 0xb8b8b8
#define grey72 0xb8b8b8
#define gray73 0xbababa
#define grey73 0xbababa
#define gray74 0xbdbdbd
#define grey74 0xbdbdbd
#define gray75 0xbfbfbf
#define grey75 0xbfbfbf
#define gray76 0xc2c2c2
#define grey76 0xc2c2c2
#define gray77 0xc4c4c4
#define grey77 0xc4c4c4
#define gray78 0xc7c7c7
#define grey78 0xc7c7c7
#define gray79 0xc9c9c9
#define grey79 0xc9c9c9
#define gray80 0xcccccc
#define grey80 0xcccccc
#define gray81 0xcfcfcf
#define grey81 0xcfcfcf
#define gray82 0xd1d1d1
#define grey82 0xd1d1d1
#define gray83 0xd4d4d4
#define grey83 0xd4d4d4
#define gray84 0xd6d6d6
#define grey84 0xd6d6d6
#define gray85 0xd9d9d9
#define grey85 0xd9d9d9
#define gray86 0xdbdbdb
#define grey86 0xdbdbdb
#define gray87 0xdedede
#define grey87 0xdedede
#define gray88 0xe0e0e0
#define grey88 0xe0e0e0
#define gray89 0xe3e3e3
#define grey89 0xe3e3e3
#define gray90 0xe5e5e5
#define grey90 0xe5e5e5
#define gray91 0xe8e8e8
#define grey91 0xe8e8e8
#define gray92 0xebebeb
#define grey92 0xebebeb
#define gray93 0xededed
#define grey93 0xededed
#define gray94 0xf0f0f0
#define grey94 0xf0f0f0
#define gray95 0xf2f2f2
#define grey95 0xf2f2f2
#define gray96 0xf5f5f5
#define grey96 0xf5f5f5
#define gray97 0xf7f7f7
#define grey97 0xf7f7f7
#define gray98 0xfafafa
#define grey98 0xfafafa
#define gray99 0xfcfcfc
#define grey99 0xfcfcfc
#define gray100 0xffffff
#define grey100 0xffffff
#define dark grey 0xa9a9a9
#define darkgrey 0xa9a9a9
#define dark gray 0xa9a9a9
#define darkgray 0xa9a9a9
#define dark blue 0x8b
#define darkblue 0x8b
#define dark cyan 0x8b8b
#define darkcyan 0x8b8b
#define dark magenta 0x8b008b
#define darkmagenta 0x8b008b
#define dark red 0x8b0000
#define darkred 0x8b0000
#define light green 0x90ee90
#define lightgreen 0x90ee90
