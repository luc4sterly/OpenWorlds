// 004183e0 FUN_004183e0 [Global]
// programa: gamma.dll

int __cdecl FUN_004183e0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwFindNamedTexture(param_1);
  if (iVar1 != 0) {
    iVar2 = RwGetTextureData(iVar1);
    if (iVar2 == 0) {
      RwDestroyTexture(iVar1);
      iVar1 = 0;
    }
    else {
      RwSetTextureData(iVar1,iVar2 + 1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


