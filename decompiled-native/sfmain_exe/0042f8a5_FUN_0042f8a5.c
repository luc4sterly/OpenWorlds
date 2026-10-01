// 0042f8a5 FUN_0042f8a5 [Global]
// program: sfmain.exe

void __fastcall FUN_0042f8a5(undefined4 param_1,int *param_2)

{
  byte bVar1;
  byte *in_EAX;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    bVar1 = *in_EAX;
    if ((bVar1 < 0x30) || (bVar1 != 0x39 && 0x38 < bVar1)) break;
    in_EAX = in_EAX + 1;
    iVar2 = (uint)bVar1 + iVar2 * 10 + -0x30;
  }
  *param_2 = iVar2;
  return;
}


