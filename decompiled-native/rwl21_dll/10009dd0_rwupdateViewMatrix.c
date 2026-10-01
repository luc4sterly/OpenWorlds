// 10009dd0 rwupdateViewMatrix [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* rwupdateViewMatrix */

uint __cdecl rwupdateViewMatrix(int param_1)

{
  float *pfVar1;
  float fVar2;
  undefined4 in_EAX;
  uint uVar3;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST0_04;
  undefined8 uVar4;
  float local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x9dd0  566  _rwupdateViewMatrix */
  uVar3 = CONCAT31((int3)((uint)in_EAX >> 8),*(char *)(param_1 + 0xfd));
  if (*(char *)(param_1 + 0xfd) != '\0') {
    fVar2 = -*(float *)(param_1 + 0x90) * _DAT_10052098;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    if (*(int *)(param_1 + 0x218) == 2) {
      pfVar1 = (float *)(param_1 + 0x24);
      RwScaleVector((float *)(param_1 + 4),fVar2,&local_c);
      fVar2 = -(*(float *)(param_1 + 0x48) * fVar2);
      FUN_100428a0(&local_c,pfVar1,fVar2,&local_c);
      *(float *)(param_1 + 0xbc) = local_c;
      *(undefined4 *)(param_1 + 0xcc) = local_8;
      *(undefined4 *)(param_1 + 0xdc) = local_4;
      RwDotProduct(&local_c,local_8);
      *(float *)(param_1 + 0xec) = (float)((float10)_DAT_10052098 - (extraout_ST0 + (float10)fVar2))
      ;
      fVar2 = -*(float *)(param_1 + 0x94) * _DAT_10052098;
      RwScaleVector((float *)(param_1 + 0x14),fVar2,&local_c);
      fVar2 = *(float *)(param_1 + 0x4c) * fVar2;
      FUN_100428a0(&local_c,pfVar1,fVar2,&local_c);
      *(float *)(param_1 + 0xc0) = local_c;
      *(undefined4 *)(param_1 + 0xd0) = local_8;
      *(undefined4 *)(param_1 + 0xe0) = local_4;
      RwDotProduct(&local_c,local_8);
      *(float *)(param_1 + 0xf0) =
           (float)((float10)_DAT_10052098 - (extraout_ST0_00 + (float10)fVar2));
      *(float *)(param_1 + 0xc4) = *pfVar1;
      *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0x2c);
      uVar4 = RwDotProduct(*pfVar1,*(undefined4 *)(param_1 + 0x28));
      uVar3 = (uint)uVar4;
      *(undefined4 *)(param_1 + 200) = 0;
      *(float *)(param_1 + 0xf4) = (float)-extraout_ST0_01;
      *(undefined4 *)(param_1 + 0xd8) = 0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
      *(undefined4 *)(param_1 + 0xf8) = 0x3f800000;
      *(undefined1 *)(param_1 + 0xfc) = 0;
    }
    else {
      pfVar1 = (float *)(param_1 + 0x24);
      RwScaleVector((float *)(param_1 + 4),fVar2,&local_c);
      fVar2 = _DAT_10052098 - *(float *)(param_1 + 0x48) * fVar2;
      FUN_100428a0(&local_c,pfVar1,fVar2,&local_c);
      *(float *)(param_1 + 0xbc) = local_c;
      *(undefined4 *)(param_1 + 0xcc) = local_8;
      *(undefined4 *)(param_1 + 0xdc) = local_4;
      RwDotProduct(&local_c,local_8);
      *(float *)(param_1 + 0xec) =
           (float)((float10)_DAT_10052098 - (extraout_ST0_02 + (float10)fVar2));
      fVar2 = -*(float *)(param_1 + 0x94) * _DAT_10052098;
      RwScaleVector((float *)(param_1 + 0x14),fVar2,&local_c);
      fVar2 = *(float *)(param_1 + 0x4c) * fVar2 + _DAT_10052098;
      FUN_100428a0(&local_c,pfVar1,fVar2,&local_c);
      *(float *)(param_1 + 0xc0) = local_c;
      *(undefined4 *)(param_1 + 0xd0) = local_8;
      *(undefined4 *)(param_1 + 0xe0) = local_4;
      RwDotProduct(&local_c,local_8);
      *(float *)(param_1 + 0xf0) =
           (float)((float10)_DAT_10052098 - (extraout_ST0_03 + (float10)fVar2));
      *(float *)(param_1 + 0xc4) = *pfVar1;
      *(undefined4 *)(param_1 + 0xd4) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0x2c);
      RwDotProduct(*pfVar1,*(undefined4 *)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0xf8) = 0x3f800000;
      *(float *)(param_1 + 0xf4) = (float)-extraout_ST0_04;
      uVar3 = 0;
      *(undefined4 *)(param_1 + 200) = 0;
      *(undefined4 *)(param_1 + 0xd8) = 0;
      *(undefined4 *)(param_1 + 0xe8) = 0;
      *(undefined1 *)(param_1 + 0xfc) = 0;
    }
    *(undefined1 *)(param_1 + 0xfd) = 0;
  }
  return uVar3;
}


