// 00419000 FUN_00419000 [Global]
// programa: gamma.dll

int FUN_00419000(void)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwCreateMaterial();
  if (iVar1 != 0) {
    RwSetMaterialTextureModes(iVar1,DAT_00489574);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


