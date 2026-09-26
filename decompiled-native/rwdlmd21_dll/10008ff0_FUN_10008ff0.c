// 10008ff0 FUN_10008ff0 [Global]
// programa: rwdlmd21.dll

undefined4 __thiscall FUN_10008ff0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_10007610(this);
  iVar1 = FUN_10009100((byte *)(param_1 + 0x252));
  iVar2 = FUN_10009100((byte *)((199 - iVar1) * 3 + param_1));
  iVar2 = (199 - iVar1) - iVar2;
  iVar1 = FUN_10009100((byte *)(iVar2 * 3 + 3 + param_1));
  iVar1 = (iVar2 + 1) - iVar1;
  iVar2 = FUN_10009100((byte *)(iVar1 * 3 + 3 + param_1));
  iVar2 = (iVar1 + 1) - iVar2;
  iVar1 = FUN_10009100((byte *)(iVar2 * 3 + 3 + param_1));
  iVar1 = (iVar2 + 1) - iVar1;
  iVar2 = FUN_10009100((byte *)(iVar1 * 3 + 3 + param_1));
  iVar2 = (iVar1 + 1) - iVar2;
  iVar1 = FUN_10009100((byte *)(iVar2 * 3 + 3 + param_1));
  iVar2 = (iVar2 - iVar1) + 2;
  iVar1 = FUN_10009100((byte *)(iVar2 * 3 + param_1));
  iVar2 = iVar2 - iVar1;
  iVar1 = FUN_10009100((byte *)(iVar2 * 3 + 3 + param_1));
  FUN_10009100((byte *)(((iVar2 + 1) - iVar1) * 3 + 3 + param_1));
  return 0xdd;
}


