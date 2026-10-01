// 00418370 FUN_00418370 [Global]
// program: gamma.dll

void __cdecl FUN_00418370(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  if (param_1 != 0) {
    iVar1 = RwGetTextureData(param_1);
    if (iVar1 < 2) {
      puVar2 = (undefined4 *)0x0;
      iVar1 = RwGetTextureRaster(param_1);
      if (iVar1 != 0) {
        puVar2 = (undefined4 *)RwGetRasterData(iVar1);
      }
      RwDestroyTexture(param_1);
      if (puVar2 != (undefined4 *)0x0) {
        FUN_00454a60(puVar2);
      }
    }
    else {
      RwSetTextureData(param_1,iVar1 + -1);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


