// 00417c40 FUN_00417c40 [Global]
// program: gamma.dll

/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_00417c40(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  int local_2c;
  int local_28;
  int local_24 [5];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  if ((param_1 != 0) && (param_2 != 0)) {
    local_24[0] = 0;
    local_2c = 0;
    local_28 = 0;
    RwGetClumpVertexViewportPosition(param_1,1,param_2,&local_2c,&local_28,local_24);
    if (local_24[0] != 0) {
      local_24[4] = 0;
      local_24[3] = 0;
      local_24[1] = 0;
      local_24[2] = 0;
      RwGetCameraViewport(param_2,local_24 + 1,local_24 + 2,local_24 + 3,local_24 + 4);
      if ((((-1 < local_2c + -2) && (local_2c + 1 <= local_24[3] + -1)) && (-1 < local_28 + -2)) &&
         (local_28 + 1 <= local_24[4] + -1)) {
        iVar2 = RwGetCameraRaster(param_2);
        if (iVar2 != 0) {
          iVar3 = RwGetRasterDepth(iVar2);
          if (iVar3 == 0x10) {
            uVar1 = RwGetClumpData(param_1);
            iVar3 = RwGetRasterStride(iVar2);
            iVar7 = local_28 + -2;
            iVar4 = local_2c + -2;
            iVar5 = RwGetRasterPixels(iVar2);
            if (iVar5 != 0) {
              puVar6 = (undefined2 *)(iVar7 * iVar3 + iVar4 * 2 + iVar5);
              *puVar6 = uVar1;
              puVar6[1] = uVar1;
              puVar6[2] = uVar1;
              puVar6[3] = uVar1;
              puVar6 = (undefined2 *)((int)puVar6 + iVar3);
              *puVar6 = uVar1;
              puVar6[1] = uVar1;
              puVar6[2] = uVar1;
              puVar6[3] = uVar1;
              puVar6 = (undefined2 *)((int)puVar6 + iVar3);
              *puVar6 = uVar1;
              puVar6[1] = uVar1;
              puVar6[2] = uVar1;
              puVar6[3] = uVar1;
              puVar6 = (undefined2 *)((int)puVar6 + iVar3);
              *puVar6 = uVar1;
              puVar6[1] = uVar1;
              puVar6[2] = uVar1;
              puVar6[3] = uVar1;
              RwReleaseRasterPixels(iVar2,iVar5);
            }
          }
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


