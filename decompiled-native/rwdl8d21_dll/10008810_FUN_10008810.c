// 10008810 FUN_10008810 [Global]
// program: RWDL8D21.DLL

undefined4 __thiscall FUN_10008810(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_10006da0(this);
  iVar1 = FUN_10008920((byte *)(param_1 + 0x252));
  iVar2 = FUN_10008920((byte *)((199 - iVar1) * 3 + param_1));
  iVar2 = (199 - iVar1) - iVar2;
  iVar1 = FUN_10008920((byte *)(iVar2 * 3 + 3 + param_1));
  iVar1 = (iVar2 + 1) - iVar1;
  iVar2 = FUN_10008920((byte *)(iVar1 * 3 + 3 + param_1));
  iVar2 = (iVar1 + 1) - iVar2;
  iVar1 = FUN_10008920((byte *)(iVar2 * 3 + 3 + param_1));
  iVar1 = (iVar2 + 1) - iVar1;
  iVar2 = FUN_10008920((byte *)(iVar1 * 3 + 3 + param_1));
  iVar2 = (iVar1 + 1) - iVar2;
  iVar1 = FUN_10008920((byte *)(iVar2 * 3 + 3 + param_1));
  iVar2 = (iVar2 - iVar1) + 2;
  iVar1 = FUN_10008920((byte *)(iVar2 * 3 + param_1));
  iVar2 = iVar2 - iVar1;
  iVar1 = FUN_10008920((byte *)(iVar2 * 3 + 3 + param_1));
  FUN_10008920((byte *)(((iVar2 + 1) - iVar1) * 3 + 3 + param_1));
  return 0xdd;
}


