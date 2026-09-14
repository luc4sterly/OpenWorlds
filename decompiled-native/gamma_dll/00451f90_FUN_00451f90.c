// 00451f90 FUN_00451f90 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_00451f90(void *this,undefined4 param_1,undefined4 param_2,int param_3)

{
  double dVar1;
  double dVar2;
  byte bVar9;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  uint local_9c;
  char local_90 [40];
  int local_68;
  int local_64;
  undefined4 local_60;
  int local_5c;
  undefined4 local_58;
  int local_54;
  undefined2 local_50;
  undefined2 uStack_4e;
  int local_48;
  undefined2 local_44;
  int local_40;
  undefined2 local_3c;
  int local_38;
  undefined2 local_34;
  int local_30 [2];
  int local_28;
  undefined2 local_24;
  double local_1c;
  undefined4 local_14;
  
  FUN_00407570(this);
  *(undefined2 *)((int)this + 4) = 0;
  if (param_3 < 0x12) {
    FUN_0044d650((int)local_90,s_____Le_004817ac);
    uVar3 = FUN_0044d690(local_90);
    FUN_004537b0(this,(undefined4 *)local_90,uVar3);
    iVar4 = FUN_004088e0(this);
    pcVar5 = (char *)(iVar4 + 0x23);
    pcVar6 = (char *)FUN_004089f0(this);
    if (pcVar5 != pcVar6) {
      do {
        *(short *)((int)this + 4) = *(short *)((int)this + 4) * 10;
        *(short *)((int)this + 4) = *(short *)((int)this + 4) + *pcVar5 + -0x30;
        pcVar5 = pcVar5 + 1;
        pcVar6 = (char *)FUN_004089f0(this);
      } while (pcVar5 != pcVar6);
    }
    iVar4 = FUN_004088e0(this);
    if (*(char *)(iVar4 + 0x22) == '-') {
      *(short *)((int)this + 4) = -*(short *)((int)this + 4);
    }
    iVar7 = FUN_004089f0(this);
    iVar8 = FUN_004088e0(this);
    FUN_00408f50(this,(iVar4 + 0x21) - iVar8,iVar7 - (iVar4 + 0x21),0,0);
    FUN_004088e0(this);
    iVar4 = FUN_004088e0(this);
    iVar7 = FUN_004088e0(this);
    FUN_00408f50(this,(iVar4 + 1) - iVar7,1,0,0);
    FUN_004088e0(this);
    pcVar5 = (char *)FUN_004088e0(this);
    pcVar6 = (char *)FUN_004089f0(this);
    if (pcVar5 != pcVar6) {
      do {
        *pcVar5 = *pcVar5 + -0x30;
        pcVar5 = pcVar5 + 1;
        pcVar6 = (char *)FUN_004089f0(this);
      } while (pcVar5 != pcVar6);
    }
  }
  else if (_DAT_004817b8 < (double)CONCAT44(param_2,param_1)) {
    fVar10 = (float10)(double)CONCAT44(param_2,param_1);
    fVar12 = fVar10;
    if (fVar10 != (float10)0) {
      fVar12 = (float10)extract_significand(fVar10);
      fVar11 = (float10)extract_exponent(fVar10);
      fVar10 = (float10)_DAT_00480a88 * fVar12;
      fVar12 = (float10)1 + fVar11;
    }
    local_68 = (int)ROUND(fVar12);
    dVar1 = (double)fVar10;
    FUN_00452940(&local_48,(short)local_68);
    FUN_00406490(&local_64,&local_48);
    local_60 = CONCAT22(local_60._2_2_,local_44);
    FUN_00404ed0(&local_48);
    FUN_00452940(&local_40,-0x20);
    FUN_00406490(&local_5c,&local_40);
    local_58 = CONCAT22(local_58._2_2_,local_3c);
    FUN_00404ed0(&local_40);
    FUN_00407570(&local_54);
    local_50 = 0;
    bVar9 = (byte)((ushort)((ushort)(NAN(_DAT_004817b8) || NAN(dVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_004817b8 == dVar1) << 0xe) >> 8);
    while (bVar9 != 0x40) {
      local_14 = 0x20;
      fVar12 = (float10)fscale((float10)dVar1,(float10)0x20);
      dVar2 = (double)ROUND(fVar12);
      dVar1 = (double)(fVar12 - ROUND(fVar12));
      local_1c = dVar2;
      FUN_00406490(&local_38,&local_5c);
      local_34 = (undefined2)local_58;
      FUN_00452730(&local_64,&local_38);
      FUN_00404ed0(&local_38);
      if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_004817b8) || NAN(dVar2)) << 10) >> 8) |
                (byte)((ushort)((ushort)(_DAT_004817b8 == dVar2) << 0xe) >> 8)) != 0x40) {
        FUN_004093a0(&local_54,&local_64,0,0xffffffff);
        local_50 = (undefined2)local_60;
        local_9c = (uint)(longlong)ROUND(dVar2);
        FUN_00451e60(local_30,local_9c);
        FUN_00452730(&local_54,local_30);
        FUN_00404ed0(local_30);
        FUN_00406490(&local_28,&local_54);
        local_24 = local_50;
        FUN_00452510(this,&local_28);
        FUN_00404ed0(&local_28);
      }
      bVar9 = (byte)((ushort)((ushort)(NAN(_DAT_004817b8) || NAN(dVar1)) << 10) >> 8) |
              (byte)((ushort)((ushort)(_DAT_004817b8 == dVar1) << 0xe) >> 8);
    }
    FUN_00404ed0(&local_54);
    FUN_00404ed0(&local_5c);
    FUN_00404ed0(&local_64);
  }
  return this;
}


