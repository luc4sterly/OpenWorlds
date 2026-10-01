// 00434670 FUN_00434670 [Global]
// program: gamma.dll

undefined4 __thiscall FUN_00434670(void *this,int param_1,void *param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar3;
  int local_58;
  undefined4 local_50 [4];
  int local_40 [8];
  uint local_20 [2];
  uint local_18 [2];
  
  local_50[0] = DAT_004754e0;
  local_50[1] = DAT_004754e4;
  local_50[2] = DAT_004754e8;
  local_50[3] = DAT_004754ec;
  local_58 = 0;
  bVar1 = false;
  if (((byte)((byte)((ushort)((ushort)(NAN(*(float *)(param_1 + 4)) ||
                                      NAN(*(float *)((int)this + 4))) << 10) >> 8) |
             (byte)((ushort)((ushort)(*(float *)(param_1 + 4) == *(float *)((int)this + 4)) << 0xe)
                   >> 8)) == 0x40) &&
     ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(param_1 + 8)) || NAN(*(float *)((int)this + 8))
                                     ) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 8) == *(float *)((int)this + 8)) << 0xe)
                  >> 8)) == 0x40)) {
    bVar1 = true;
  }
  if ((bVar1) &&
     ((byte)((byte)((ushort)((ushort)(NAN(*(float *)(param_1 + 0xc)) ||
                                     NAN(*(float *)((int)this + 0xc))) << 10) >> 8) |
            (byte)((ushort)((ushort)(*(float *)(param_1 + 0xc) == *(float *)((int)this + 0xc)) <<
                           0xe) >> 8)) == 0x40)) {
    local_58 = 1;
  }
  uVar2 = FUN_00428e60(param_2,(int)this + 0x10);
  local_40[5] = 0;
  local_40[4] = 10;
  local_40[3] = 0;
  local_40[0] = 10;
  local_40[2] = 0x1e;
  local_40[1] = 0;
  uVar3 = local_50[local_58 * 2 + (uVar2 & 0xff)];
  switch(*(undefined4 *)((int)this + 0x2c)) {
  case 1:
    switch(uVar3) {
    case 2:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 2;
    case 3:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 3;
    }
    break;
  case 2:
    switch(uVar3) {
    case 1:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 1;
    default:
      return 2;
    case 3:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 3;
    }
  case 3:
    switch(uVar3) {
    case 1:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 4;
    case 2:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 2;
    default:
      return 3;
    }
  case 4:
    switch(uVar3) {
    case 2:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 2;
    case 3:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 3;
    }
    FUN_00427c50((int *)local_20,(int *)((int)this + 0x30),local_40 + 2);
    bVar1 = FUN_00427bb0(local_20,param_3);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      uVar3 = 4;
    }
    else {
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      uVar3 = 5;
    }
    return uVar3;
  case 5:
    switch(uVar3) {
    case 2:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 2;
    case 3:
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      return 3;
    }
    FUN_00427c50((int *)local_18,(int *)((int)this + 0x30),local_40 + 4);
    bVar1 = FUN_00427bb0(local_18,param_3);
    if (CONCAT31(extraout_var_01,bVar1) == 0) {
      uVar3 = 5;
    }
    else {
      *(uint *)((int)this + 0x30) = *param_3;
      *(uint *)((int)this + 0x34) = param_3[1];
      uVar3 = 4;
    }
    return uVar3;
  default:
    return 1;
  }
  FUN_00427c50(local_40 + 6,(int *)((int)this + 0x30),local_40);
  bVar1 = FUN_00427bb0((uint *)(local_40 + 6),param_3);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    uVar3 = 1;
  }
  else {
    *(uint *)((int)this + 0x30) = *param_3;
    *(uint *)((int)this + 0x34) = param_3[1];
    uVar3 = 4;
  }
  return uVar3;
}


