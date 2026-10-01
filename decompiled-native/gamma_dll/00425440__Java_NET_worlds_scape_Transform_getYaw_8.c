// 00425440 _Java_NET_worlds_scape_Transform_getYaw@8 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _Java_NET_worlds_scape_Transform_getYaw_8(int *param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  LPVOID pvVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float local_1c;
  float local_18;
  undefined4 uStack_14;
  
                    /* 0x25440  321  _Java_NET_worlds_scape_Transform_getYaw@8 */
  local_1c = DAT_00471bf8;
  local_18 = DAT_00471bfc;
  uStack_14 = DAT_00471c00;
  uVar2 = FUN_00419950();
  uVar3 = FUN_00419950();
  uVar4 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00418f00(uVar4,uVar3);
  fVar6 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  fVar7 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  fVar8 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  FUN_00418b10(uVar3,DAT_00471bf4 / (float)fVar6,DAT_00471bf4 / (float)fVar7,
               DAT_00471bf4 / (float)fVar8);
  FUN_00419890(uVar3,uVar2);
  FUN_004198f0();
  FUN_0041a0b0(&local_1c,uVar2);
  FUN_004198f0();
  fVar1 = local_1c * local_1c + local_18 * local_18;
  if (fVar1 < (float)_DAT_00471c08) {
    pvVar5 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar5 + 4) = 0x21;
    fVar1 = _DAT_004823b0;
  }
  else {
    fVar1 = SQRT(fVar1);
  }
  fVar6 = (float10)fVar1;
  if ((float10)local_1c < fVar6) {
    if (-fVar6 < (float10)local_1c) {
      fVar6 = (float10)local_1c / fVar6;
      fVar6 = (float10)fpatan(fVar6,SQRT((float10)1 - fVar6 * fVar6));
      fVar6 = (float10)(_DAT_00471c14 *
                        (float)((float10)_DAT_00471c18 * (float10)3.141592653589793 - fVar6) *
                       (float)_DAT_00471c20);
    }
    else {
      fVar6 = (float10)_DAT_00471c14;
    }
  }
  else {
    fVar6 = (float10)DAT_00471c10;
  }
  if ((byte)(local_18 < DAT_00471c10 |
            (byte)((ushort)((ushort)(NAN(local_18) || NAN(DAT_00471c10)) << 10) >> 8)) == 1) {
    fVar6 = -fVar6;
  }
  fVar6 = (float10)_DAT_00471c28 - fVar6;
  if ((byte)(fVar6 < (float10)DAT_00471c10 |
            (byte)((ushort)((ushort)(NAN(fVar6) || NAN((float10)DAT_00471c10)) << 10) >> 8)) == 1) {
    fVar6 = fVar6 + (float10)_DAT_00471c2c;
  }
  return fVar6;
}


