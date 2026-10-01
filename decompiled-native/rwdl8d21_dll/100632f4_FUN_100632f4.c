// 100632f4 FUN_100632f4 [Global]
// program: RWDL8D21.DLL

undefined8 __fastcall FUN_100632f4(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  
  lVar1 = (longlong)param_3 * (longlong)param_4;
  iVar3 = (int)((ulonglong)lVar1 >> 0x20);
  uVar2 = (uint)lVar1 >> 0x10 | iVar3 << 0x10;
  if ((iVar3 != (short)((ulonglong)lVar1 >> 0x20)) &&
     (uVar2 = 0x7fffffff, (char)((ulonglong)lVar1 >> 0x28) < '\0')) {
    uVar2 = 0x80000000;
  }
  return CONCAT44(param_2,uVar2);
}


