// 100088c0 FUN_100088c0 [Global]
// programa: RWDL6D21.DLL

undefined4 __thiscall FUN_100088c0(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_10006e50(this);
  iVar1 = FUN_100089d0((byte *)(param_1 + 0x252));
  iVar2 = FUN_100089d0((byte *)((199 - iVar1) * 3 + param_1));
  iVar2 = (199 - iVar1) - iVar2;
  iVar1 = FUN_100089d0((byte *)(iVar2 * 3 + 3 + param_1));
  iVar1 = (iVar2 + 1) - iVar1;
  iVar2 = FUN_100089d0((byte *)(iVar1 * 3 + 3 + param_1));
  iVar2 = (iVar1 + 1) - iVar2;
  iVar1 = FUN_100089d0((byte *)(iVar2 * 3 + 3 + param_1));
  iVar1 = (iVar2 + 1) - iVar1;
  iVar2 = FUN_100089d0((byte *)(iVar1 * 3 + 3 + param_1));
  iVar2 = (iVar1 + 1) - iVar2;
  iVar1 = FUN_100089d0((byte *)(iVar2 * 3 + 3 + param_1));
  iVar2 = (iVar2 - iVar1) + 2;
  iVar1 = FUN_100089d0((byte *)(iVar2 * 3 + param_1));
  iVar2 = iVar2 - iVar1;
  iVar1 = FUN_100089d0((byte *)(iVar2 * 3 + 3 + param_1));
  FUN_100089d0((byte *)(((iVar2 + 1) - iVar1) * 3 + 3 + param_1));
  return 0xdd;
}


