// 10017010 RwSphericalTexturizeClump [Global]
// programa: RWL21.DLL

int RwSphericalTexturizeClump(int param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  int iVar2;
  byte *pbVar3;
  longlong lVar4;
  float local_18 [2];
  uint local_10;
  undefined4 local_8;
  
                    /* 0x17010  494  RwSphericalTexturizeClump */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar2 = 8;
  iVar1 = *(int *)(param_1 + 0x88);
  if (8 < *(int *)(iVar1 + 8)) {
    pbVar3 = (byte *)(iVar1 + 0x3f4);
    do {
      local_8 = *(undefined4 *)(pbVar3 + 8);
      local_10 = *(uint *)(pbVar3 + 0xc);
      local_18[0] = *(float *)(pbVar3 + 4);
      local_18[1] = 0.0;
      if ((ABS(local_18[0]) == 0.0) && ((local_10 & 0x7fffffff) == 0)) {
        local_18[0] = 1.0;
      }
      RwNormalize(local_18);
      if ((int)local_18[0] < 0x3f800001) {
        if (0xbf800000 < (uint)local_18[0]) {
          local_18[0] = -1.0;
        }
      }
      else {
        local_18[0] = 1.0;
      }
      FUN_10044a62(extraout_ECX);
      iVar2 = iVar2 + 1;
      lVar4 = __ftol();
      *(uint *)(pbVar3 + 0x20) = (int)lVar4 + 0x8000U & 0xffff;
      lVar4 = __ftol();
      *(uint *)(pbVar3 + 0x1c) = (int)lVar4 + 0x8000U & 0xffff;
      *pbVar3 = *pbVar3 | 0x80;
      pbVar3 = pbVar3 + 0x74;
    } while (iVar2 < *(int *)(iVar1 + 8));
  }
  return param_1;
}


