// 1002dde0 FUN_1002dde0 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1002dde0(float *param_1,int param_2,int param_3)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  bool bVar4;
  float10 fVar5;
  float local_50;
  float *local_4c;
  float *local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float *local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  float *local_8;
  float *local_4;
  
  local_18 = 2;
  bVar4 = false;
  local_50 = -0.01;
  if ((*(int *)(param_2 + 0x44) != 1) ||
     (local_4c = *(float **)(param_2 + 0x48), *(char *)(local_4c + 0x10) != '\0')) {
    local_4c = (float *)0x0;
  }
  if ((*(int *)(param_2 + 0x44) == 1) && (*(char *)(*(int *)(param_2 + 0x48) + 0x40) == '\0')) {
    pfVar2 = (float *)(*(int *)(param_2 + 0x48) + 0x44);
  }
  else {
    pfVar2 = (float *)0x0;
  }
  if ((local_4c != (float *)0x0) && (*(char *)((int)local_4c + 0x41) != '\0')) {
    FUN_1001c650(local_4c,pfVar2);
    *(undefined1 *)((int)local_4c + 0x41) = 0;
  }
  if ((*(int *)(param_3 + 0x44) != 1) ||
     (local_48 = *(float **)(param_3 + 0x48), *(char *)(local_48 + 0x10) != '\0')) {
    local_48 = (float *)0x0;
  }
  if ((*(int *)(param_3 + 0x44) == 1) && (*(char *)(*(int *)(param_3 + 0x48) + 0x40) == '\0')) {
    local_1c = (float *)(*(int *)(param_3 + 0x48) + 0x44);
  }
  else {
    local_1c = (float *)0x0;
  }
  if ((local_48 != (float *)0x0) && (*(char *)((int)local_48 + 0x41) != '\0')) {
    FUN_1001c650(local_48,local_1c);
    *(undefined1 *)((int)local_48 + 0x41) = 0;
  }
  local_14 = (*(float *)(param_3 + 0x1c) + *(float *)(param_3 + 0x20)) * _DAT_10052238;
  local_10 = (*(float *)(param_3 + 0x24) + *(float *)(param_3 + 0x28)) * _DAT_10052238;
  local_c = (*(float *)(param_3 + 0x2c) + *(float *)(param_3 + 0x30)) * _DAT_10052238;
  if (local_48 != (float *)0x0) {
    RwTransformPoint(&local_14,local_48);
  }
  if (pfVar2 != (float *)0x0) {
    RwTransformPoint(&local_14,pfVar2);
  }
  if ((((*(float *)(param_2 + 0x1c) <= local_14) && (local_14 < *(float *)(param_2 + 0x20))) &&
      (*(float *)(param_2 + 0x24) <= local_10)) &&
     (((local_10 < *(float *)(param_2 + 0x28) && (*(float *)(param_2 + 0x2c) <= local_c)) &&
      (local_c < *(float *)(param_2 + 0x30))))) {
    return 2;
  }
  local_14 = (*(float *)(param_2 + 0x20) + *(float *)(param_2 + 0x1c)) * _DAT_10052238;
  local_10 = (*(float *)(param_2 + 0x24) + *(float *)(param_2 + 0x28)) * _DAT_10052238;
  local_c = (*(float *)(param_2 + 0x2c) + *(float *)(param_2 + 0x30)) * _DAT_10052238;
  if (local_4c != (float *)0x0) {
    RwTransformPoint(&local_14,local_4c);
  }
  if (local_1c != (float *)0x0) {
    RwTransformPoint(&local_14,local_1c);
  }
  if (((*(float *)(param_3 + 0x1c) <= local_14) && (local_14 < *(float *)(param_3 + 0x20))) &&
     ((*(float *)(param_3 + 0x24) <= local_10 &&
      (((local_10 < *(float *)(param_3 + 0x28) && (*(float *)(param_3 + 0x2c) <= local_c)) &&
       (local_c < *(float *)(param_3 + 0x30))))))) {
    return 2;
  }
  pfVar3 = (float *)&DAT_1005adb8;
  do {
    if (&DAT_1005add0 < pfVar3) break;
    if (local_4c == (float *)0x0) {
      local_30 = *pfVar3;
      local_2c = pfVar3[1];
      local_28 = pfVar3[2];
LAB_1002e0e1:
      FUN_1002d750(param_2,&local_38,&local_38,(uint *)param_2,&local_30);
      FUN_1002d750(&local_30,param_3,&local_40,(uint *)param_3,&local_30);
      local_44 = local_38 - local_3c;
      local_20 = local_38;
      bVar4 = local_50 < local_44;
      if (bVar4) {
        param_1[3] = -local_38;
        *param_1 = local_30;
        param_1[1] = local_2c;
        param_1[2] = local_28;
        local_18 = 3;
        local_24 = local_3c;
      }
      else {
        local_44 = local_40 - local_34;
        local_24 = local_34;
        local_20 = local_40;
        bVar4 = local_50 < local_44;
        if (!bVar4) goto LAB_1002e1ca;
        param_1[3] = -local_40;
        *param_1 = local_30;
        param_1[1] = local_2c;
        param_1[2] = local_28;
        local_18 = 1;
      }
      param_1[4] = -local_24;
      local_50 = local_44;
    }
    else {
      local_30 = *pfVar2;
      local_2c = pfVar2[4];
      local_28 = pfVar2[8];
      fVar5 = rwLengthNormaliseVector(&local_30,&local_30);
      if ((float10)_DAT_1005223c < fVar5) goto LAB_1002e0e1;
      bVar4 = false;
    }
LAB_1002e1ca:
    pfVar3 = pfVar3 + 3;
    pfVar2 = pfVar2 + 1;
  } while (!bVar4);
  if (((local_4c != (float *)0x0) || (local_48 != (float *)0x0)) && (!bVar4)) {
    pfVar3 = (float *)&DAT_1005adb8;
    pfVar2 = local_1c;
    do {
      if (&DAT_1005add0 < pfVar3) break;
      if (local_48 == (float *)0x0) {
        local_30 = *pfVar3;
        local_2c = pfVar3[1];
        local_28 = pfVar3[2];
LAB_1002e262:
        FUN_1002d750(param_2,&local_38,&local_38,(uint *)param_2,&local_30);
        FUN_1002d750(&local_30,param_3,&local_40,(uint *)param_3,&local_30);
        local_44 = local_38 - local_3c;
        local_20 = local_38;
        bVar4 = local_50 < local_44;
        if (bVar4) {
          param_1[3] = -local_38;
          *param_1 = local_30;
          param_1[1] = local_2c;
          param_1[2] = local_28;
          local_18 = 3;
          local_24 = local_3c;
        }
        else {
          local_44 = local_40 - local_34;
          local_24 = local_34;
          local_20 = local_40;
          bVar4 = local_50 < local_44;
          if (!bVar4) goto LAB_1002e34b;
          param_1[3] = -local_40;
          *param_1 = local_30;
          param_1[1] = local_2c;
          param_1[2] = local_28;
          local_18 = 1;
        }
        param_1[4] = -local_24;
        local_50 = local_44;
      }
      else {
        local_30 = *pfVar2;
        local_2c = pfVar2[4];
        local_28 = pfVar2[8];
        fVar5 = rwLengthNormaliseVector(&local_30,&local_30);
        if ((float10)_DAT_1005223c < fVar5) goto LAB_1002e262;
        bVar4 = false;
      }
LAB_1002e34b:
      pfVar3 = pfVar3 + 3;
      pfVar2 = pfVar2 + 1;
    } while (!bVar4);
    if (!bVar4) {
      local_8 = (float *)&DAT_1005adb8;
      local_4 = local_4c;
      do {
        if (&DAT_1005add0 < local_8) {
          return local_18;
        }
        local_1c = local_4;
        if (local_4c == (float *)0x0) {
          local_1c = local_8;
        }
        if (!bVar4) {
          pfVar3 = (float *)&DAT_1005adb8;
          pfVar2 = local_48;
          do {
            if (&DAT_1005add0 < pfVar3) break;
            pfVar1 = pfVar2;
            if (local_48 == (float *)0x0) {
              pfVar1 = pfVar3;
            }
            RwCrossProduct(local_1c,pfVar1,&local_30);
            fVar5 = rwLengthNormaliseVector(&local_30,&local_30);
            bVar4 = false;
            if ((float10)_DAT_1005223c < fVar5) {
              FUN_1002d750(param_2,&local_38,&local_38,(uint *)param_2,&local_30);
              FUN_1002d750(&local_30,param_3,&local_40,(uint *)param_3,&local_30);
              local_44 = local_38 - local_3c;
              local_20 = local_38;
              bVar4 = local_50 < local_44;
              if (bVar4) {
                param_1[3] = -local_38;
                *param_1 = local_30;
                param_1[1] = local_2c;
                param_1[2] = local_28;
                local_18 = 3;
                local_24 = local_3c;
              }
              else {
                local_44 = local_40 - local_34;
                local_24 = local_34;
                local_20 = local_40;
                bVar4 = local_50 < local_44;
                if (!bVar4) goto LAB_1002e4dd;
                param_1[3] = -local_40;
                *param_1 = local_30;
                param_1[1] = local_2c;
                param_1[2] = local_28;
                local_18 = 1;
              }
              param_1[4] = -local_24;
              local_50 = local_44;
            }
LAB_1002e4dd:
            pfVar3 = pfVar3 + 3;
            pfVar2 = pfVar2 + 4;
          } while (!bVar4);
        }
        local_8 = local_8 + 3;
        local_4 = local_4 + 4;
      } while (!bVar4);
    }
  }
  return local_18;
}


