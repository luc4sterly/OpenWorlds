// 00418430 FUN_00418430 [Global]
// program: gamma.dll

int __cdecl FUN_00418430(int param_1,int param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = 0;
  if (param_2 != 0) {
    iVar1 = RwReadTexture(param_2);
    if (iVar1 != 0) {
      RwSetTextureData(iVar1,1);
      if (param_1 != 0) {
        RwAddTextureToDict(param_1,iVar1);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


