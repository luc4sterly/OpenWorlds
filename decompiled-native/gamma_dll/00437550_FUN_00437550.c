// 00437550 FUN_00437550 [Global]
// program: gamma.dll

void * __cdecl FUN_00437550(void *param_1,int param_2,uint param_3,byte *param_4,int param_5)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_64;
  undefined4 local_60 [5];
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  byte local_3c;
  byte local_3b;
  byte local_3a;
  byte local_39;
  undefined4 local_38 [5];
  undefined4 local_24 [5];
  
  FUN_004378b0((void *)(param_2 + 4),param_3);
  *(int *)(param_2 + 0x10) = param_5;
  local_64 = 0;
  FUN_00428f10(local_60);
  local_40 = 0.0;
  local_4c = 0.0;
  local_44 = 0.0;
  local_48 = 0.0;
  local_64 = (uint)*param_4;
  if (param_5 == 4) {
    FUN_0042f460(param_1,(undefined1 *)&local_4c,4);
  }
  else {
    FUN_0042f460(param_1,(undefined1 *)&local_4c,4);
    FUN_0042f460(param_1,(undefined1 *)&local_48,4);
    FUN_0042f460(param_1,(undefined1 *)&local_44,4);
    FUN_0042f460(param_1,(undefined1 *)&local_40,4);
  }
  FUN_00428fe0(local_38,local_4c,local_48,local_44,local_40);
  FUN_00428e20(local_60,(int)local_38);
  FUN_00428e50(local_38);
  FUN_00437830((void *)(param_2 + 4),&local_64);
  iVar3 = 1;
  if (1 < (int)param_3) {
    do {
      local_64 = local_64 + param_4[iVar3];
      if (param_5 == 4) {
        FUN_0042f460(param_1,&local_3c,1);
        fVar1 = *(float *)(&DAT_00475c40 + (local_3c & 0x7f) * 4);
        if (0x7f < local_3c) {
          fVar1 = -fVar1;
        }
        local_4c = local_4c + fVar1;
      }
      else {
        FUN_0042f460(param_1,&local_3b,3);
        uVar2 = (int)(uint)local_3b >> 2;
        fVar1 = *(float *)(&DAT_00475bc0 + (uVar2 & 0x1f) * 4);
        if (0x1f < uVar2) {
          fVar1 = -fVar1;
        }
        uVar2 = ((int)(uint)local_3a >> 4) + (local_3b & 3) * 0x10;
        local_4c = local_4c + fVar1;
        fVar1 = *(float *)(&DAT_00475bc0 + (uVar2 & 0x1f) * 4);
        if (0x1f < uVar2) {
          fVar1 = -fVar1;
        }
        uVar2 = (uint)local_39;
        local_48 = local_48 + fVar1;
        uVar4 = ((int)uVar2 >> 6) + (local_3a & 0xf) * 4;
        fVar1 = *(float *)(&DAT_00475bc0 + (uVar4 & 0x1f) * 4);
        if (0x1f < uVar4) {
          fVar1 = -fVar1;
        }
        local_44 = local_44 + fVar1;
        fVar1 = *(float *)(&DAT_00475bc0 + (uVar2 & 0x1f) * 4);
        if (0x1f < (uVar2 & 0x3f)) {
          fVar1 = -fVar1;
        }
        local_40 = local_40 + fVar1;
      }
      FUN_00428fe0(local_24,local_4c,local_48,local_44,local_40);
      FUN_00428e20(local_60,(int)local_24);
      FUN_00428e50(local_24);
      FUN_00437830((void *)(param_2 + 4),&local_64);
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_3);
  }
  FUN_00428e50(local_60);
  return param_1;
}


