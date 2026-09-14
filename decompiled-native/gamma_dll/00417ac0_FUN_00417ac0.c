// 00417ac0 FUN_00417ac0 [Global]
// programa: gamma.dll

void __cdecl FUN_00417ac0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwGetClumpParent(param_1);
  if (iVar1 != 0) {
    RwRemoveChildFromClump(param_1);
  }
  iVar1 = RwGetClumpOwner(param_1);
  if (iVar1 != 0) {
    iVar2 = RwDefaultScene();
    if (iVar1 != iVar2) {
      RwRemoveClumpFromScene(param_1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


