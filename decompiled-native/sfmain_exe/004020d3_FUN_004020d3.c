// 004020d3 FUN_004020d3 [Global]
// programa: sfmain.exe

void FUN_004020d3(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = 0x67452301;
  in_EAX[1] = 0xefcdab89;
  in_EAX[2] = 0x98badcfe;
  in_EAX[3] = 0x10325476;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  return;
}


