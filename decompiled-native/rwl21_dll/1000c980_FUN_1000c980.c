// 1000c980 FUN_1000c980 [Global]
// programa: RWL21.DLL

bool FUN_1000c980(void)

{
  *(undefined4 *)(PTR_DAT_1005b69c + 0xc) = 0;
  DAT_1005a090 = FUN_100371c0(s_cameralist_1005a098,0x22c);
  return (bool)('\x01' - (DAT_1005a090 == (undefined4 *)0x0));
}


