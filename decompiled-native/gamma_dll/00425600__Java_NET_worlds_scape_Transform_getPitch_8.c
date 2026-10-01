// 00425600 _Java_NET_worlds_scape_Transform_getPitch@8 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _Java_NET_worlds_scape_Transform_getPitch_8(int *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  LPVOID pvVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float local_5c;
  float local_1c;
  float local_18;
  float local_14;
  
                    /* 0x25600  317  _Java_NET_worlds_scape_Transform_getPitch@8 */
  local_1c = DAT_00471c30;
  local_18 = DAT_00471c34;
  local_14 = DAT_00471c38;
  uVar4 = FUN_00419950();
  uVar5 = FUN_00419950();
  uVar6 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00418f00(uVar6,uVar5);
  fVar8 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  fVar9 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  fVar10 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  FUN_00418b10(uVar5,DAT_00471bf4 / (float)fVar8,DAT_00471bf4 / (float)fVar9,
               DAT_00471bf4 / (float)fVar10);
  FUN_00419890(uVar5,uVar4);
  FUN_004198f0();
  FUN_0041a0b0(&local_1c,uVar4);
  FUN_004198f0();
  fVar1 = local_1c * local_1c + local_18 * local_18;
  fVar2 = local_14 * local_14 + fVar1;
  if (fVar2 < (float)_DAT_00471c08) {
    pvVar7 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar7 + 4) = 0x21;
    fVar2 = _DAT_004823b0;
  }
  else {
    fVar2 = SQRT(fVar2);
  }
  if (fVar1 < (float)_DAT_00471c08) {
    pvVar7 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar7 + 4) = 0x21;
    fVar3 = _DAT_004823b0;
  }
  else {
    fVar3 = SQRT(fVar1);
  }
  local_5c = DAT_00471c10;
  if (fVar3 < fVar2) {
    if (fVar1 < (float)_DAT_00471c08) {
      pvVar7 = FUN_00453ed0();
      *(undefined4 *)((int)pvVar7 + 4) = 0x21;
      fVar2 = _DAT_004823b0;
    }
    else {
      fVar2 = SQRT(fVar1);
    }
    fVar1 = local_14 * local_14 + fVar1;
    if (fVar1 < (float)_DAT_00471c08) {
      pvVar7 = FUN_00453ed0();
      *(undefined4 *)((int)pvVar7 + 4) = 0x21;
      fVar1 = _DAT_004823b0;
    }
    else {
      fVar1 = SQRT(fVar1);
    }
    fVar8 = (float10)fVar2 / (float10)fVar1;
    fVar8 = (float10)fpatan(fVar8,SQRT((float10)1 - fVar8 * fVar8));
    local_5c = _DAT_00471c14 * (float)((float10)_DAT_00471c18 * (float10)3.141592653589793 - fVar8)
               * (float)_DAT_00471c20;
  }
  if ((byte)(local_14 < DAT_00471c10 |
            (byte)((ushort)((ushort)(NAN(local_14) || NAN(DAT_00471c10)) << 10) >> 8)) == 1) {
    local_5c = -local_5c;
  }
  return (float10)local_5c;
}


