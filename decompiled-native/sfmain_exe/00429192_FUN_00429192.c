// 00429192 FUN_00429192 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00429192(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  UINT in_EAX;
  int iVar2;
  undefined4 extraout_ECX;
  
  iVar1 = DAT_0043d884;
  iVar2 = LoadStringA(DAT_004627bc,in_EAX,(LPSTR)(DAT_0043d884 * 0x50 + 0x4c756c),0x4f);
  if (iVar2 < 0) {
    FUN_0042c5c6(extraout_ECX,&DAT_0043744c);
  }
  DAT_0043d884 = (DAT_0043d884 + 1) % 10;
  return CONCAT44(param_2,iVar1 * 0x50 + 0x4c756c);
}


