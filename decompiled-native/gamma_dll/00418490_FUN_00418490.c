// 00418490 FUN_00418490 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00418490(int param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  undefined4 local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_14 = 1;
  if (((param_1 != 0) && (param_2 != (uint *)0x0)) &&
     (iVar2 = RwGetTextureRaster(param_1), iVar2 != 0)) {
    iVar3 = RwGetRasterData(iVar2);
    if (((DAT_00489578 == 0) || (iVar3 != 0)) && ((DAT_00489578 != 0 || (iVar3 == 0)))) {
      local_14 = 0;
    }
    else {
      puVar4 = (uint *)RwGetRasterPixels(iVar2);
      if (puVar4 != (uint *)0x0) {
        puVar5 = puVar4;
        for (iVar3 = DAT_00489570 >> 2; iVar3 != 0; iVar3 = iVar3 + -1) {
          uVar1 = *param_2;
          param_2 = param_2 + 1;
          *puVar5 = uVar1 | 0x10001;
          puVar5 = puVar5 + 1;
        }
        RwReleaseRasterPixels(iVar2,puVar4);
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return local_14;
}


