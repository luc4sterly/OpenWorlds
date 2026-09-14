// 00432a30 FUN_00432a30 [Global]
// programa: gamma.dll

void __thiscall FUN_00432a30(void *this,int param_1,int param_2,int *param_3)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  undefined3 extraout_var;
  undefined4 uVar9;
  uint local_64;
  undefined4 local_60;
  int local_5c [2];
  int local_54 [4];
  undefined **local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34 [5];
  int local_20 [2];
  uint local_18;
  undefined4 local_14;
  
  if (*(int **)this == (int *)0x0) {
    return;
  }
  (**(code **)(**(int **)this + 0x10))(local_5c);
  local_54[0] = 0;
  local_54[1] = 0;
  bVar6 = true;
  bVar4 = false;
  bVar5 = false;
  iVar8 = FUN_00427b00(local_5c,local_54);
  if (iVar8 == 0) {
    bVar3 = false;
    (**(code **)(**(int **)this + 0x10))(local_54 + 2);
    bVar7 = FUN_00427b30(local_54 + 2,param_3);
    if (CONCAT31(extraout_var,bVar7) != 0) {
      bVar2 = true;
      (**(code **)(**(int **)this + 8))(&local_44);
      bVar1 = false;
      bVar5 = true;
      bVar7 = false;
      if (((byte)((byte)((ushort)((ushort)(NAN(local_40) || NAN(*(float *)(param_1 + 4))) << 10) >>
                        8) |
                 (byte)((ushort)((ushort)(local_40 == *(float *)(param_1 + 4)) << 0xe) >> 8)) ==
           0x40) &&
         ((byte)((byte)((ushort)((ushort)(NAN(local_3c) || NAN(*(float *)(param_1 + 8))) << 10) >> 8
                       ) |
                (byte)((ushort)((ushort)(local_3c == *(float *)(param_1 + 8)) << 0xe) >> 8)) == 0x40
         )) {
        bVar7 = true;
      }
      if ((bVar7) &&
         ((byte)((byte)((ushort)((ushort)(NAN(local_38) || NAN(*(float *)(param_1 + 0xc))) << 10) >>
                       8) |
                (byte)((ushort)((ushort)(local_38 == *(float *)(param_1 + 0xc)) << 0xe) >> 8)) ==
          0x40)) {
        bVar1 = true;
      }
      if (bVar1) {
        (**(code **)(**(int **)this + 0xc))(local_34);
        bVar4 = true;
        uVar9 = FUN_00428eb0(local_34,param_2);
        if ((char)uVar9 == '\0') {
          bVar2 = false;
        }
      }
      if (bVar2) {
        bVar3 = true;
      }
    }
    if (!bVar3) {
      bVar6 = false;
    }
  }
  if (bVar4) {
    FUN_00428e50(local_34);
  }
  if (bVar5) {
    local_44 = &PTR_LAB_00473390;
  }
  if (bVar6) {
    (**(code **)(**(int **)this + 0x10))(local_20);
    FUN_00427cb0((int *)&local_18,param_3,local_20);
    local_64 = local_18;
    local_60 = local_14;
    iVar8 = FUN_00427b70(&DAT_0049dd7c,&local_64);
    if (iVar8 != 0) {
      local_60 = DAT_0049dd80;
      local_64 = DAT_0049dd7c;
    }
    (**(code **)(**(int **)this + 4))(param_1,param_2,param_3,&local_64);
  }
  return;
}


