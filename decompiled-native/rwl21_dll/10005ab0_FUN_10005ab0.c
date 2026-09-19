// 10005ab0 FUN_10005ab0 [Global]
// programa: RWL21.DLL

int FUN_10005ab0(int param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  
  if ((param_1 == 0) || (param_2 == (float *)0x0)) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x88);
    pfVar3 = (float *)(iVar2 + 0x3ac);
    pfVar1 = (float *)(iVar2 + 0xc + *(int *)(iVar2 + 8) * 0x74);
    if (pfVar1 < pfVar3) {
      *(undefined4 *)(param_1 + 0xc4) = 0;
      local_74 = *pfVar3;
      local_70 = *(float *)(iVar2 + 0x3b0);
      local_6c = *(float *)(iVar2 + 0x3b4);
      RwTransformPoint(&local_74,param_2);
      *pfVar3 = local_74;
      *(float *)(iVar2 + 0x3b0) = local_70;
      *(float *)(iVar2 + 0x3b4) = local_6c;
      local_8c = local_74;
      local_88 = local_74;
      local_84 = local_70;
      local_80 = local_70;
      local_7c = local_6c;
      local_78 = local_6c;
      for (pfVar3 = (float *)(iVar2 + 0x420); pfVar3 < pfVar1; pfVar3 = pfVar3 + 0x1d) {
        local_74 = *pfVar3;
        local_70 = pfVar3[1];
        local_6c = pfVar3[2];
        RwTransformPoint(&local_74,param_2);
        *pfVar3 = local_74;
        pfVar3[1] = local_70;
        pfVar3[2] = local_6c;
        if (local_8c <= local_74) {
          if (local_88 < local_74) {
            local_88 = local_74;
          }
        }
        else {
          local_8c = local_74;
        }
        if (local_84 <= local_70) {
          if (local_80 < local_70) {
            local_80 = local_70;
          }
        }
        else {
          local_84 = local_70;
        }
        if (local_7c <= local_6c) {
          if (local_78 < local_6c) {
            local_78 = local_6c;
          }
        }
        else {
          local_7c = local_6c;
        }
      }
      iVar2 = *(int *)(param_1 + 0x88);
      *(float *)(iVar2 + 0xc) = local_8c;
      *(float *)(iVar2 + 0xf4) = local_8c;
      *(float *)(iVar2 + 0x1dc) = local_8c;
      *(float *)(iVar2 + 0x2c4) = local_8c;
      *(float *)(iVar2 + 0x80) = local_88;
      *(float *)(iVar2 + 0x168) = local_88;
      *(float *)(iVar2 + 0x250) = local_88;
      *(float *)(iVar2 + 0x338) = local_88;
      *(float *)(iVar2 + 0x16c) = local_84;
      *(float *)(iVar2 + 0xf8) = local_84;
      *(float *)(iVar2 + 0x33c) = local_84;
      *(float *)(iVar2 + 0x2c8) = local_84;
      *(float *)(iVar2 + 0x84) = local_80;
      *(float *)(iVar2 + 0x10) = local_80;
      *(float *)(iVar2 + 0x254) = local_80;
      *(float *)(iVar2 + 0x1e0) = local_80;
      *(float *)(iVar2 + 600) = local_7c;
      *(float *)(iVar2 + 0x1e4) = local_7c;
      *(float *)(iVar2 + 0x340) = local_7c;
      *(float *)(iVar2 + 0x2cc) = local_7c;
      *(float *)(iVar2 + 0x88) = local_78;
      *(float *)(iVar2 + 0x14) = local_78;
      *(float *)(iVar2 + 0x170) = local_78;
      *(float *)(iVar2 + 0xfc) = local_78;
    }
  }
  return param_1;
}


