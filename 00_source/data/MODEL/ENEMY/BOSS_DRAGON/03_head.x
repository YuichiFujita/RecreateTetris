xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 181;
 -1.93740;12.30744;-48.37956;,
 -0.00504;11.20212;-50.66724;,
 -0.00504;2.47344;-42.31080;,
 -0.00504;23.53284;-57.40836;,
 -81.75012;31.04556;31.72776;,
 -88.34053;27.52284;30.04620;,
 -124.21572;42.51936;55.28496;,
 -57.74880;20.61648;10.18428;,
 -69.77388;14.65836;5.25096;,
 -20.38596;3.69336;-13.98048;,
 -18.64908;-0.69852;-8.30784;,
 -21.99024;2.34420;-5.21124;,
 -75.80892;30.17652;37.38144;,
 -51.98940;21.57756;17.31648;,
 -24.02064;11.55336;-10.14468;,
 -14.22756;-5.80704;-13.40160;,
 -15.86628;-9.77124;-10.82904;,
 -17.62800;-4.02408;-11.54724;,
 -14.22756;-5.53956;-17.01360;,
 -18.64908;-0.69852;-8.30784;,
 -17.73312;1.33452;-17.64168;,
 -16.70532;-2.01408;-14.32944;,
 -16.70532;-2.01408;-14.32944;,
 -14.22756;-5.53956;-17.01360;,
 -13.29804;-5.10228;-23.28876;,
 -81.75012;25.47612;32.93016;,
 -18.90660;17.18844;2.85840;,
 -12.80004;18.71904;-8.46324;,
 -16.94208;8.87316;-17.49144;,
 -0.00504;26.95584;-18.29952;,
 -15.27444;27.28680;7.85916;,
 -0.00504;62.16864;33.64584;,
 -15.91008;5.92464;-23.28060;,
 -9.72828;9.46272;-26.47104;,
 -14.87436;2.96652;-29.08956;,
 -11.14452;13.72956;-18.16860;,
 -18.64908;-0.69852;-8.30784;,
 -16.70532;-2.01408;-14.32944;,
 -18.19572;-2.17476;-9.74604;,
 -26.74440;17.73000;6.20328;,
 -57.74880;11.53548;11.40996;,
 -18.64908;-0.69852;-8.30784;,
 -14.22756;-4.13820;-7.18368;,
 -18.90660;17.18844;2.85840;,
 -0.00504;-1.17000;15.32784;,
 -0.00504;13.24572;28.04364;,
 -12.31824;2.53860;21.13620;,
 -13.75512;4.81764;1.79124;,
 -14.22756;-4.13820;-7.18368;,
 -18.19572;-2.17476;-9.74604;,
 -16.94208;8.87316;-17.49144;,
 -15.91008;5.92464;-23.28060;,
 -14.22756;-4.13820;-7.18368;,
 -0.00504;14.26836;-32.09232;,
 -19.68060;-5.83404;8.68380;,
 -14.22756;-4.13820;-7.18368;,
 -0.00504;-1.91040;-3.02688;,
 -19.68060;-5.83404;8.68380;,
 -0.00504;13.77408;10.76640;,
 -0.00504;-1.17000;15.32784;,
 -18.90660;17.18844;2.85840;,
 -16.94208;8.87316;-17.49144;,
 -17.73312;1.33452;-17.64168;,
 -3.85968;4.68516;-39.35040;,
 -3.44016;14.79000;-45.52500;,
 -5.21664;9.65064;-33.64236;,
 -0.00504;17.09940;-44.75028;,
 -0.00504;14.26836;-32.09232;,
 1.93740;12.30744;-48.37956;,
 124.21572;42.51936;55.28496;,
 88.34053;27.52284;30.04620;,
 81.75012;31.04556;31.72776;,
 69.77388;14.65836;5.25096;,
 57.74880;20.61648;10.18428;,
 21.99024;2.34420;-5.21124;,
 18.64908;-0.69852;-8.30784;,
 20.38596;3.69336;-13.98048;,
 75.80892;30.17652;37.38144;,
 51.98940;21.57756;17.31648;,
 24.02064;11.55336;-10.14468;,
 17.62800;-4.02408;-11.54724;,
 15.86628;-9.77124;-10.82904;,
 14.22756;-5.80704;-13.40160;,
 14.22756;-5.53956;-17.01360;,
 16.70532;-2.01408;-14.32944;,
 17.73312;1.33452;-17.64168;,
 18.64908;-0.69852;-8.30784;,
 16.70532;-2.01408;-14.32944;,
 13.29804;-5.10228;-23.28876;,
 14.22756;-5.53956;-17.01360;,
 81.75012;25.47612;32.93016;,
 16.94208;8.87316;-17.49144;,
 12.80004;18.71904;-8.46324;,
 18.90660;17.18844;2.85840;,
 15.27444;27.28680;7.85916;,
 14.87436;2.96652;-29.08956;,
 9.72828;9.46272;-26.47104;,
 15.91008;5.92464;-23.28060;,
 11.14452;13.72956;-18.16860;,
 18.19572;-2.17476;-9.74604;,
 16.70532;-2.01408;-14.32944;,
 18.64908;-0.69852;-8.30784;,
 57.74880;11.53548;11.40996;,
 26.74440;17.73000;6.20328;,
 18.90660;17.18844;2.85840;,
 14.22756;-4.13820;-7.18368;,
 18.64908;-0.69852;-8.30784;,
 12.31824;2.53860;21.13620;,
 13.75512;4.81764;1.79124;,
 18.19572;-2.17476;-9.74604;,
 14.22756;-4.13820;-7.18368;,
 15.91008;5.92464;-23.28060;,
 16.94208;8.87316;-17.49144;,
 14.22756;-4.13820;-7.18368;,
 19.68060;-5.83404;8.68380;,
 19.68060;-5.83404;8.68380;,
 14.22756;-4.13820;-7.18368;,
 16.94208;8.87316;-17.49144;,
 18.90660;17.18844;2.85840;,
 17.73312;1.33452;-17.64168;,
 3.85968;4.68516;-39.35040;,
 3.44016;14.79000;-45.52500;,
 5.21664;9.65064;-33.64236;,
 -11.43132;-10.03428;-26.95056;,
 -13.30416;-4.81500;-30.48228;,
 -10.44396;-9.95364;-32.75340;,
 -10.75188;-6.65664;-35.74392;,
 -5.64120;-13.22748;-41.72340;,
 -5.49408;-9.42660;-42.95676;,
 -0.00504;-13.00008;-49.50564;,
 -0.00504;-16.00704;-43.88880;,
 -15.63444;-1.28988;-23.42976;,
 -3.85968;4.68516;-39.35040;,
 -6.04248;1.08708;-40.03776;,
 -6.43740;-3.73212;-40.87716;,
 -0.00504;-1.75368;-45.17124;,
 -0.00504;2.47344;-42.31080;,
 -0.00504;-7.06584;-47.80896;,
 -0.00504;13.77408;10.76640;,
 -14.87436;2.96652;-29.08956;,
 -6.43740;-3.73212;-40.87716;,
 -0.00504;-7.06584;-47.80896;,
 -5.21664;9.65064;-33.64236;,
 10.44396;-9.95364;-32.75340;,
 13.30416;-4.81500;-30.48228;,
 11.43132;-10.03428;-26.95056;,
 5.64120;-13.22748;-41.72340;,
 10.75188;-6.65664;-35.74392;,
 5.49408;-9.42660;-42.95676;,
 15.63444;-1.28988;-23.42976;,
 6.04248;1.08708;-40.03776;,
 3.85968;4.68516;-39.35040;,
 6.43740;-3.73212;-40.87716;,
 14.87436;2.96652;-29.08956;,
 6.43740;-3.73212;-40.87716;,
 5.21664;9.65064;-33.64236;,
 -5.64120;-13.22748;-41.72340;,
 -0.00504;-16.00704;-43.88880;,
 -0.00504;-12.60036;-41.83248;,
 -10.44396;-9.95364;-32.75340;,
 -0.00504;-5.63064;-27.17412;,
 -11.43132;-10.03428;-26.95056;,
 -13.29804;-5.10228;-23.28876;,
 -0.00504;-2.21544;-13.53696;,
 -14.22756;-5.53956;-17.01360;,
 -15.86628;-9.77124;-10.82904;,
 -14.22756;-5.80704;-13.40160;,
 -14.22756;-4.13820;-7.18368;,
 -14.22756;-5.80704;-13.40160;,
 -14.22756;-4.13820;-7.18368;,
 -0.00504;-1.91040;-3.02688;,
 5.64120;-13.22748;-41.72340;,
 10.44396;-9.95364;-32.75340;,
 11.43132;-10.03428;-26.95056;,
 13.29804;-5.10228;-23.28876;,
 14.22756;-5.53956;-17.01360;,
 14.22756;-4.13820;-7.18368;,
 14.22756;-5.80704;-13.40160;,
 15.86628;-9.77124;-10.82904;,
 14.22756;-5.80704;-13.40160;,
 14.22756;-4.13820;-7.18368;;
 
 224;
 3;0,1,2;,
 3;0,3,1;,
 3;4,5,6;,
 3;5,7,8;,
 3;9,10,11;,
 3;6,12,4;,
 3;13,4,12;,
 3;14,8,7;,
 3;15,16,17;,
 3;17,18,15;,
 3;19,20,21;,
 3;17,22,18;,
 3;23,20,24;,
 3;25,6,5;,
 3;26,27,28;,
 3;29,30,31;,
 3;32,33,34;,
 3;27,29,35;,
 3;8,25,5;,
 3;36,37,38;,
 3;39,40,11;,
 3;6,25,12;,
 3;25,13,12;,
 3;41,42,43;,
 3;44,45,46;,
 3;42,47,43;,
 3;5,4,7;,
 3;13,7,4;,
 3;17,48,49;,
 3;26,30,27;,
 3;29,27,30;,
 3;35,28,27;,
 3;8,40,25;,
 3;25,40,13;,
 3;32,35,33;,
 3;35,32,28;,
 3;20,50,51;,
 3;23,21,20;,
 3;17,16,48;,
 3;49,22,17;,
 3;38,52,36;,
 3;35,53,33;,
 3;53,35,29;,
 3;47,54,46;,
 3;55,56,57;,
 3;58,46,45;,
 3;46,54,44;,
 3;57,56,59;,
 3;54,47,42;,
 3;46,58,47;,
 3;14,60,61;,
 3;7,39,14;,
 3;60,11,10;,
 3;61,9,14;,
 3;8,11,40;,
 3;9,62,10;,
 3;14,9,8;,
 3;39,13,40;,
 3;14,39,60;,
 3;7,13,39;,
 3;60,39,11;,
 3;61,62,9;,
 3;8,9,11;,
 3;1,0,3;,
 3;1,2,0;,
 3;2,63,0;,
 3;0,64,3;,
 3;0,63,64;,
 3;63,65,64;,
 3;64,66,3;,
 3;64,65,66;,
 3;65,67,66;,
 3;2,1,68;,
 3;1,3,68;,
 3;69,70,71;,
 3;72,73,70;,
 3;74,75,76;,
 3;71,77,69;,
 3;77,71,78;,
 3;73,72,79;,
 3;80,81,82;,
 3;82,83,80;,
 3;84,85,86;,
 3;83,87,80;,
 3;88,85,89;,
 3;70,69,90;,
 3;91,92,93;,
 3;31,94,29;,
 3;95,96,97;,
 3;98,29,92;,
 3;70,90,72;,
 3;99,100,101;,
 3;74,102,103;,
 3;77,90,69;,
 3;77,78,90;,
 3;104,105,106;,
 3;107,45,44;,
 3;104,108,105;,
 3;73,71,70;,
 3;71,73,78;,
 3;109,110,80;,
 3;92,94,93;,
 3;94,92,29;,
 3;92,91,98;,
 3;90,102,72;,
 3;78,102,90;,
 3;96,98,97;,
 3;91,97,98;,
 3;111,112,85;,
 3;85,84,89;,
 3;110,81,80;,
 3;80,87,109;,
 3;101,113,99;,
 3;96,53,98;,
 3;29,98,53;,
 3;107,114,108;,
 3;115,56,116;,
 3;45,107,58;,
 3;44,114,107;,
 3;59,56,115;,
 3;105,108,114;,
 3;108,58,107;,
 3;117,118,79;,
 3;79,103,73;,
 3;75,74,118;,
 3;79,76,117;,
 3;102,74,72;,
 3;75,119,76;,
 3;72,76,79;,
 3;102,78,103;,
 3;118,103,79;,
 3;103,78,73;,
 3;74,103,118;,
 3;76,119,117;,
 3;74,76,72;,
 3;3,68,1;,
 3;68,2,1;,
 3;68,120,2;,
 3;3,121,68;,
 3;121,120,68;,
 3;121,122,120;,
 3;3,66,121;,
 3;66,122,121;,
 3;66,67,122;,
 3;123,124,125;,
 3;24,124,123;,
 3;125,126,127;,
 3;128,129,127;,
 3;129,130,127;,
 3;124,24,131;,
 3;33,132,133;,
 3;34,133,134;,
 3;135,134,133;,
 3;133,136,135;,
 3;137,134,135;,
 3;138,31,30;,
 3;30,26,138;,
 3;131,139,124;,
 3;131,24,20;,
 3;34,33,133;,
 3;128,140,129;,
 3;129,140,141;,
 3;20,51,131;,
 3;131,51,139;,
 3;124,126,125;,
 3;127,126,128;,
 3;43,47,58;,
 3;33,53,142;,
 3;132,33,142;,
 3;133,132,136;,
 3;143,144,145;,
 3;145,144,88;,
 3;146,147,143;,
 3;146,129,148;,
 3;146,130,129;,
 3;149,88,144;,
 3;150,151,96;,
 3;152,150,95;,
 3;150,152,135;,
 3;135,136,150;,
 3;135,152,137;,
 3;94,31,138;,
 3;138,93,94;,
 3;144,153,149;,
 3;85,88,149;,
 3;150,96,95;,
 3;129,154,148;,
 3;141,154,129;,
 3;149,111,85;,
 3;153,111,149;,
 3;143,147,144;,
 3;148,147,146;,
 3;58,108,104;,
 3;155,53,96;,
 3;155,96,151;,
 3;136,151,150;,
 3;156,157,158;,
 3;159,158,160;,
 3;161,159,160;,
 3;162,161,160;,
 3;160,163,162;,
 3;162,163,164;,
 3;165,166,167;,
 3;168,164,163;,
 3;169,168,163;,
 3;159,156,158;,
 3;169,163,170;,
 3;158,157,171;,
 3;160,158,172;,
 3;160,172,173;,
 3;160,173,174;,
 3;174,163,160;,
 3;175,163,174;,
 3;176,177,178;,
 3;163,175,179;,
 3;163,179,180;,
 3;158,171,172;,
 3;170,163,180;,
 3;140,128,126;,
 3;140,124,139;,
 3;140,126,124;,
 3;147,148,154;,
 3;153,144,154;,
 3;144,147,154;;
 
 MeshMaterialList {
  4;
  224;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  0,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\MODEL\\dragonBoss000.png";
   }
  }
  Material {
   0.257600;0.147200;0.150400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.241600;0.241600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.260000;0.075200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.325000;0.094000;;
  }
 }
 MeshNormals {
  188;
  -0.650295;0.700373;-0.294268;,
  -0.742638;-0.157794;-0.650838;,
  -0.524546;-0.750591;-0.401827;,
  -0.631516;0.282718;-0.721982;,
  -0.137549;0.452965;-0.880853;,
  -0.843512;-0.240911;-0.480051;,
  -0.685817;0.581606;-0.437480;,
  -0.686192;0.602116;-0.408163;,
  0.000080;-0.811820;0.583907;,
  0.000082;-0.907530;0.419987;,
  0.000062;-0.996271;0.086275;,
  -0.634110;0.769060;0.080313;,
  -0.733989;-0.258635;-0.627987;,
  0.000053;-0.999976;0.006971;,
  0.000062;-0.661506;0.749940;,
  0.000042;-0.879169;0.476511;,
  -0.790951;-0.362442;-0.492983;,
  -0.824084;-0.322004;-0.466046;,
  -0.614452;0.744369;0.261465;,
  -0.458121;0.798109;-0.391341;,
  0.164061;0.967899;-0.190409;,
  0.234328;0.967249;-0.097567;,
  0.012464;0.907624;-0.419600;,
  -0.203750;0.753298;-0.625322;,
  -0.211103;0.666048;-0.715413;,
  -0.915947;-0.303103;-0.263002;,
  -0.713962;0.488720;-0.501409;,
  -0.047828;0.895534;-0.442416;,
  0.044355;0.923848;-0.380180;,
  -0.789415;-0.374762;-0.486187;,
  -0.883158;-0.388225;-0.263274;,
  -0.917976;-0.387297;-0.085565;,
  -0.882671;-0.465240;-0.066664;,
  -0.811500;-0.536110;-0.232495;,
  -0.181274;-0.960945;-0.209104;,
  -0.566465;-0.270902;-0.778286;,
  -0.693023;-0.468107;0.548265;,
  -0.866142;-0.489484;-0.101010;,
  -0.729341;0.175807;-0.661176;,
  -0.580157;0.418821;-0.698575;,
  -0.730267;0.555161;-0.398128;,
  -0.710589;0.583029;-0.393879;,
  -0.792111;-0.021217;-0.610009;,
  -0.933080;-0.236078;-0.271347;,
  -0.924639;-0.234406;-0.300161;,
  -0.853221;0.223618;-0.471178;,
  -0.636204;0.615657;-0.464985;,
  0.045420;-0.819263;0.571617;,
  -0.086042;-0.888457;0.450822;,
  -0.950345;-0.260825;-0.169749;,
  -0.853779;0.366118;-0.370161;,
  -0.628994;0.632901;-0.451446;,
  -0.884135;-0.453204;-0.113633;,
  -0.951040;0.008927;-0.308940;,
  -0.872549;-0.099538;-0.478279;,
  -0.841643;0.486248;-0.234946;,
  -0.836799;0.103749;-0.537590;,
  -0.920786;0.371451;0.119071;,
  -0.891696;0.445971;-0.077386;,
  0.082463;-0.751454;0.654612;,
  0.266709;-0.542196;0.796800;,
  -0.765463;-0.462425;-0.447469;,
  -0.111973;0.826329;-0.551944;,
  -0.454458;-0.877879;-0.150987;,
  -0.947238;-0.124571;-0.295335;,
  0.823151;-0.322771;-0.467163;,
  0.458121;0.798109;-0.391341;,
  -0.164061;0.967899;-0.190409;,
  -0.234328;0.967249;-0.097567;,
  -0.012464;0.907624;-0.419600;,
  0.203750;0.753298;-0.625322;,
  0.211103;0.666048;-0.715413;,
  0.915947;-0.303103;-0.263002;,
  0.713962;0.488720;-0.501409;,
  0.047828;0.895534;-0.442416;,
  -0.044355;0.923848;-0.380180;,
  0.789163;-0.374950;-0.486451;,
  0.883158;-0.388225;-0.263274;,
  0.917976;-0.387297;-0.085565;,
  0.882671;-0.465240;-0.066664;,
  0.811500;-0.536110;-0.232495;,
  0.181368;-0.960930;-0.209093;,
  0.566465;-0.270902;-0.778286;,
  0.693023;-0.468107;0.548265;,
  0.866142;-0.489484;-0.101010;,
  0.729053;0.175910;-0.661466;,
  0.579887;0.418825;-0.698796;,
  0.730099;0.555323;-0.398210;,
  0.710473;0.583143;-0.393919;,
  0.791826;-0.021181;-0.610379;,
  0.933080;-0.236078;-0.271347;,
  0.924639;-0.234406;-0.300161;,
  0.853221;0.223618;-0.471178;,
  0.636087;0.615795;-0.464961;,
  -0.045420;-0.819263;0.571617;,
  0.086042;-0.888457;0.450822;,
  0.950345;-0.260825;-0.169749;,
  0.853779;0.366118;-0.370161;,
  0.628817;0.633032;-0.451507;,
  0.884135;-0.453204;-0.113633;,
  0.951040;0.008927;-0.308940;,
  0.872549;-0.099538;-0.478279;,
  0.841436;0.486653;-0.234849;,
  0.836656;0.103563;-0.537850;,
  0.920750;0.371536;0.119079;,
  0.891696;0.445971;-0.077386;,
  -0.082398;-0.751456;0.654618;,
  -0.266709;-0.542196;0.796800;,
  0.765463;-0.462425;-0.447469;,
  0.111973;0.826329;-0.551944;,
  0.454458;-0.877879;-0.150987;,
  0.947218;-0.124405;-0.295468;,
  -0.142403;-0.898750;0.414693;,
  -0.349896;-0.925889;0.142484;,
  -0.316696;-0.947091;0.052178;,
  0.282415;-0.511788;0.811366;,
  0.132404;-0.764639;0.630711;,
  0.252267;-0.670361;0.697837;,
  -0.131600;-0.526309;0.840048;,
  -0.565324;-0.352324;0.745840;,
  -0.614723;-0.639066;0.462288;,
  -0.780206;-0.163718;0.603718;,
  -0.706802;0.700808;0.096436;,
  0.186308;-0.979362;0.078360;,
  0.137983;-0.972056;0.189915;,
  -0.663283;0.748019;0.022875;,
  -0.904651;0.324521;-0.276210;,
  0.006073;0.953498;-0.301338;,
  0.302298;-0.502974;0.809712;,
  -0.718872;0.006798;-0.695109;,
  -0.284042;0.311229;-0.906894;,
  -0.577576;0.754840;0.310843;,
  -0.574291;0.729800;0.370919;,
  -0.578408;0.776673;0.249446;,
  0.732706;-0.259701;-0.629044;,
  0.789407;-0.363617;-0.494590;,
  0.842582;-0.241420;-0.481427;,
  0.349896;-0.925889;0.142484;,
  0.142403;-0.898750;0.414693;,
  0.685952;0.602303;-0.408290;,
  0.685528;0.581849;-0.437611;,
  0.316696;-0.947091;0.052178;,
  -0.282415;-0.511788;0.811366;,
  -0.132404;-0.764639;0.630711;,
  -0.252267;-0.670361;0.697837;,
  0.565240;-0.352337;0.745897;,
  0.131600;-0.526309;0.840048;,
  0.614723;-0.639066;0.462288;,
  0.780206;-0.163718;0.603718;,
  0.649807;0.700843;-0.294229;,
  0.706619;0.700991;0.096443;,
  -0.137907;-0.972069;0.189903;,
  -0.186185;-0.979386;0.078351;,
  0.662979;0.748288;0.022884;,
  0.633811;0.769306;0.080320;,
  0.904651;0.324521;-0.276210;,
  -0.006073;0.953498;-0.301338;,
  -0.302298;-0.502974;0.809712;,
  0.718872;0.006798;-0.695109;,
  0.284042;0.311229;-0.906894;,
  0.573164;0.730504;0.371277;,
  0.613470;0.745062;0.261794;,
  0.576445;0.755535;0.311254;,
  0.577281;0.777361;0.249912;,
  -0.000308;0.560433;-0.828200;,
  -0.000114;-0.335145;0.942166;,
  -0.000139;-0.427410;0.904058;,
  -0.448730;-0.328233;0.831206;,
  -0.411640;-0.247088;0.877211;,
  0.742053;-0.157838;-0.651494;,
  0.523867;-0.750959;-0.402024;,
  0.583806;0.185515;-0.790415;,
  0.630924;0.282889;-0.722433;,
  0.448516;-0.328307;0.831293;,
  0.411453;-0.247020;0.877319;,
  0.096141;-0.750280;0.654092;,
  0.000066;-0.516769;0.856125;,
  0.208465;-0.932609;0.294590;,
  0.322791;-0.812952;0.484681;,
  0.179002;-0.907782;0.379327;,
  0.239373;-0.969520;-0.052259;,
  0.939526;-0.330770;0.088776;,
  -0.095973;-0.750326;0.654065;,
  -0.208260;-0.932668;0.294547;,
  -0.322548;-0.813060;0.484662;,
  -0.178874;-0.907812;0.379316;,
  -0.239216;-0.969558;-0.052273;,
  -0.939526;-0.330770;0.088776;;
  224;
  3;17,16,12;,
  3;17,5,16;,
  3;28,23,22;,
  3;23,27,24;,
  3;61,37,63;,
  3;22,21,28;,
  3;20,28,21;,
  3;62,24,27;,
  3;34,35,52;,
  3;52,33,34;,
  3;37,25,44;,
  3;52,44,33;,
  3;33,25,32;,
  3;48,112,113;,
  3;19,41,26;,
  3;6,40,7;,
  3;50,46,45;,
  3;41,6,51;,
  3;114,48,113;,
  3;37,44,53;,
  3;60,47,115;,
  3;112,48,116;,
  3;48,117,116;,
  3;118,36,119;,
  3;15,14,59;,
  3;36,57,119;,
  3;23,28,27;,
  3;20,27,28;,
  3;52,36,120;,
  3;19,40,41;,
  3;6,41,40;,
  3;51,26,41;,
  3;114,47,48;,
  3;48,47,117;,
  3;50,51,46;,
  3;51,50,26;,
  3;25,26,50;,
  3;33,44,25;,
  3;52,121,36;,
  3;53,44,52;,
  3;120,36,37;,
  3;51,0,46;,
  3;0,51,6;,
  3;57,58,122;,
  3;123,13,124;,
  3;11,122,125;,
  3;59,124,15;,
  3;124,13,15;,
  3;58,57,126;,
  3;122,11,57;,
  3;62,19,26;,
  3;27,127,62;,
  3;128,115,118;,
  3;26,61,129;,
  3;114,63,47;,
  3;61,25,37;,
  3;62,130,24;,
  3;60,117,47;,
  3;62,127,19;,
  3;27,20,127;,
  3;128,60,115;,
  3;26,25,61;,
  3;114,61,63;,
  3;16,17,5;,
  3;16,12,17;,
  3;12,56,17;,
  3;17,64,5;,
  3;17,56,64;,
  3;56,55,64;,
  3;131,18,132;,
  3;131,133,18;,
  3;55,0,18;,
  3;134,135,65;,
  3;135,136,65;,
  3;69,70,75;,
  3;71,74,70;,
  3;110,84,108;,
  3;75,68,69;,
  3;68,75,67;,
  3;74,71,109;,
  3;99,82,81;,
  3;81,80,99;,
  3;91,72,84;,
  3;80,91,99;,
  3;79,72,80;,
  3;137,138,95;,
  3;73,88,66;,
  3;139,87,140;,
  3;92,93,97;,
  3;98,140,88;,
  3;137,95,141;,
  3;100,91,84;,
  3;142,94,107;,
  3;143,95,138;,
  3;143,144,95;,
  3;145,83,146;,
  3;106,14,15;,
  3;145,104,83;,
  3;74,75,70;,
  3;75,74,67;,
  3;147,83,99;,
  3;88,87,66;,
  3;87,88,140;,
  3;88,73,98;,
  3;95,94,141;,
  3;144,94,95;,
  3;93,98,97;,
  3;73,97,98;,
  3;97,73,72;,
  3;72,91,80;,
  3;83,148,99;,
  3;99,91,100;,
  3;84,83,147;,
  3;93,149,98;,
  3;140,98,149;,
  3;150,105,104;,
  3;151,13,152;,
  3;153,150,154;,
  3;15,151,106;,
  3;15,13,151;,
  3;155,104,105;,
  3;104,154,150;,
  3;73,66,109;,
  3;109,156,74;,
  3;146,142,157;,
  3;158,108,73;,
  3;94,110,141;,
  3;84,72,108;,
  3;71,159,109;,
  3;94,144,107;,
  3;66,156,109;,
  3;156,67,74;,
  3;142,107,157;,
  3;108,72,73;,
  3;110,108,141;,
  3;136,65,135;,
  3;65,134,135;,
  3;65,103,134;,
  3;136,111,65;,
  3;111,103,65;,
  3;111,102,103;,
  3;160,161,162;,
  3;161,163,162;,
  3;161,149,102;,
  3;31,43,30;,
  3;32,43,31;,
  3;30,54,29;,
  3;42,1,29;,
  3;1,2,29;,
  3;43,32,49;,
  3;46,56,39;,
  3;45,39,38;,
  3;4,38,39;,
  3;39,164,4;,
  3;3,38,4;,
  3;165,166,167;,
  3;167,119,165;,
  3;49,45,43;,
  3;49,32,25;,
  3;45,46,39;,
  3;42,38,1;,
  3;1,38,3;,
  3;25,50,49;,
  3;49,50,45;,
  3;43,54,30;,
  3;29,54,42;,
  3;119,168,165;,
  3;46,0,55;,
  3;56,46,55;,
  3;39,56,12;,
  3;77,90,78;,
  3;78,90,79;,
  3;76,101,77;,
  3;76,169,89;,
  3;76,170,169;,
  3;96,79,90;,
  3;86,103,93;,
  3;85,86,92;,
  3;86,85,171;,
  3;4,164,86;,
  3;4,85,172;,
  3;173,166,165;,
  3;165,145,173;,
  3;90,92,96;,
  3;72,79,96;,
  3;86,93,92;,
  3;169,85,89;,
  3;172,85,169;,
  3;96,97,72;,
  3;92,97,96;,
  3;77,101,90;,
  3;89,101,76;,
  3;165,174,145;,
  3;102,149,93;,
  3;102,93,103;,
  3;134,103,86;,
  3;175,176,8;,
  3;177,8,9;,
  3;178,177,9;,
  3;179,178,9;,
  3;9,10,179;,
  3;179,10,180;,
  3;181,181,181;,
  3;34,180,10;,
  3;123,34,10;,
  3;177,175,8;,
  3;123,10,13;,
  3;8,176,182;,
  3;9,8,183;,
  3;9,183,184;,
  3;9,184,185;,
  3;185,10,9;,
  3;186,10,185;,
  3;187,187,187;,
  3;10,186,81;,
  3;10,81,152;,
  3;8,182,183;,
  3;13,10,152;,
  3;38,42,54;,
  3;38,43,45;,
  3;38,54,43;,
  3;101,89,85;,
  3;92,90,85;,
  3;90,101,85;;
 }
 MeshTextureCoords {
  181;
  0.098700;0.850630;,
  0.111720;0.859770;,
  0.134820;0.770960;,
  0.070160;0.967180;,
  0.784230;0.299100;,
  0.813640;0.302460;,
  0.841920;0.156710;,
  0.768790;0.430470;,
  0.801090;0.422730;,
  0.782740;0.561270;,
  0.753440;0.585290;,
  0.763620;0.542410;,
  0.755250;0.272740;,
  0.735950;0.401620;,
  0.767500;0.541650;,
  0.779670;0.149980;,
  0.810820;0.141120;,
  0.770800;0.117760;,
  0.763290;0.162790;,
  0.618910;0.426200;,
  0.595660;0.399500;,
  0.594310;0.434070;,
  0.753150;0.112180;,
  0.570100;0.454080;,
  0.538940;0.442380;,
  0.783510;0.292320;,
  0.487770;0.596040;,
  0.463240;0.597270;,
  0.486330;0.659610;,
  0.433350;0.594780;,
  0.463780;0.569300;,
  0.431140;0.535580;,
  0.487350;0.718540;,
  0.451890;0.668800;,
  0.488950;0.744480;,
  0.454930;0.637920;,
  0.629270;0.546750;,
  0.603410;0.569800;,
  0.625140;0.560870;,
  0.735080;0.518570;,
  0.764880;0.426240;,
  0.388900;0.275060;,
  0.385220;0.283860;,
  0.417470;0.264270;,
  0.405330;0.298820;,
  0.419250;0.294920;,
  0.402240;0.289390;,
  0.402240;0.289390;,
  0.790690;0.080920;,
  0.766710;0.087380;,
  0.564050;0.335780;,
  0.547540;0.345240;,
  0.639440;0.569380;,
  0.428010;0.637280;,
  0.385220;0.283860;,
  0.389350;0.263770;,
  0.397830;0.294820;,
  0.420390;0.250510;,
  0.419250;0.294920;,
  0.433890;0.294820;,
  0.731680;0.554550;,
  0.753440;0.585290;,
  0.769020;0.635110;,
  0.108780;0.752700;,
  0.076810;0.844940;,
  0.064980;0.741310;,
  0.062480;0.851840;,
  0.036330;0.755100;,
  0.098700;0.850630;,
  0.841920;0.156710;,
  0.813640;0.302460;,
  0.784230;0.299100;,
  0.801090;0.422730;,
  0.768790;0.430470;,
  0.763620;0.542410;,
  0.753440;0.585290;,
  0.782740;0.561270;,
  0.755250;0.272740;,
  0.735950;0.401620;,
  0.767500;0.541650;,
  0.770800;0.117760;,
  0.810820;0.141120;,
  0.779670;0.149980;,
  0.763290;0.162790;,
  0.594310;0.434070;,
  0.595660;0.399500;,
  0.618910;0.426200;,
  0.753150;0.112180;,
  0.538940;0.442380;,
  0.570100;0.454080;,
  0.783510;0.292320;,
  0.486330;0.659610;,
  0.463240;0.597270;,
  0.487770;0.596040;,
  0.463780;0.569300;,
  0.488950;0.744480;,
  0.451890;0.668800;,
  0.487350;0.718540;,
  0.454930;0.637920;,
  0.625140;0.560870;,
  0.603410;0.569800;,
  0.629270;0.546750;,
  0.764880;0.426240;,
  0.735080;0.518570;,
  0.417470;0.264270;,
  0.385220;0.283860;,
  0.388900;0.275060;,
  0.402240;0.289390;,
  0.402240;0.289390;,
  0.766710;0.087380;,
  0.790690;0.080920;,
  0.547540;0.345240;,
  0.564050;0.335780;,
  0.639440;0.569380;,
  0.385220;0.283860;,
  0.420390;0.250510;,
  0.389350;0.263770;,
  0.753440;0.585290;,
  0.731680;0.554550;,
  0.769020;0.635110;,
  0.108780;0.752700;,
  0.076810;0.844940;,
  0.064980;0.741310;,
  0.515430;0.477550;,
  0.482450;0.443350;,
  0.478780;0.473770;,
  0.447970;0.445200;,
  0.435820;0.494850;,
  0.406650;0.474910;,
  0.395810;0.478880;,
  0.406970;0.502020;,
  0.539500;0.417640;,
  0.444050;0.742730;,
  0.457810;0.778230;,
  0.486360;0.841060;,
  0.433970;0.810340;,
  0.441500;0.779490;,
  0.420050;0.844470;,
  0.478460;0.559130;,
  0.504630;0.367950;,
  0.429860;0.408650;,
  0.400710;0.424680;,
  0.432530;0.670040;,
  0.478780;0.473770;,
  0.482450;0.443350;,
  0.515430;0.477550;,
  0.435820;0.494850;,
  0.447970;0.445200;,
  0.406650;0.474910;,
  0.539500;0.417640;,
  0.457810;0.778230;,
  0.444050;0.742730;,
  0.486360;0.841060;,
  0.504630;0.367950;,
  0.429860;0.408650;,
  0.432530;0.670040;,
  0.939230;0.686390;,
  0.921870;0.695100;,
  0.921870;0.685490;,
  0.953990;0.647710;,
  0.921870;0.626520;,
  0.957020;0.624360;,
  0.962760;0.609630;,
  0.921870;0.571650;,
  0.965620;0.585640;,
  0.245020;0.957420;,
  0.232960;0.935310;,
  0.261790;0.928330;,
  0.965620;0.571110;,
  0.965620;0.546090;,
  0.921870;0.571650;,
  0.939230;0.686390;,
  0.953990;0.647710;,
  0.957020;0.624360;,
  0.962760;0.609630;,
  0.965620;0.585640;,
  0.261790;0.928330;,
  0.232960;0.935310;,
  0.245020;0.957420;,
  0.965620;0.571110;,
  0.965620;0.546090;;
 }
}