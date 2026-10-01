// 0040a76a FUN_0040a76a [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0040a76a(undefined4 param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int in_EAX;
  float *pfVar8;
  float *pfVar9;
  
  fVar7 = _DAT_004385e0;
  fVar6 = _DAT_004385dc;
  fVar5 = _DAT_004385d8;
  fVar4 = _DAT_004385d4;
  fVar3 = _DAT_004385d0;
  fVar2 = _DAT_004385cc;
  pfVar9 = (float *)(param_2 + 0x214);
  pfVar8 = (float *)(in_EAX + 0x214);
  do {
    *pfVar9 = (*pfVar8 + pfVar8[-0x1e]) * _DAT_004385a4;
    *pfVar9 = (pfVar8[-1] + pfVar8[-0x1d]) * _DAT_004385a8 + *pfVar9;
    *pfVar9 = (pfVar8[-2] + pfVar8[-0x1c]) * _DAT_004385ac + *pfVar9;
    *pfVar9 = (pfVar8[-3] + pfVar8[-0x1b]) * _DAT_004385b0 + *pfVar9;
    *pfVar9 = (pfVar8[-4] + pfVar8[-0x1a]) * _DAT_004385b4 + *pfVar9;
    *pfVar9 = (pfVar8[-5] + pfVar8[-0x19]) * _DAT_004385b8 + *pfVar9;
    *pfVar9 = (pfVar8[-6] + pfVar8[-0x18]) * _DAT_004385bc + *pfVar9;
    *pfVar9 = (pfVar8[-7] + pfVar8[-0x17]) * _DAT_004385c0 + *pfVar9;
    *pfVar9 = (pfVar8[-8] + pfVar8[-0x16]) * _DAT_004385c4 + *pfVar9;
    *pfVar9 = (pfVar8[-9] + pfVar8[-0x15]) * _DAT_004385c8 + *pfVar9;
    *pfVar9 = (pfVar8[-10] + pfVar8[-0x14]) * fVar2 + *pfVar9;
    *pfVar9 = (pfVar8[-0xb] + pfVar8[-0x13]) * fVar3 + *pfVar9;
    *pfVar9 = (pfVar8[-0xc] + pfVar8[-0x12]) * fVar4 + *pfVar9;
    *pfVar9 = (pfVar8[-0xd] + pfVar8[-0x11]) * fVar5 + *pfVar9;
    *pfVar9 = (pfVar8[-0xe] + pfVar8[-0x10]) * fVar6 + *pfVar9;
    pfVar1 = pfVar8 + -0xf;
    pfVar8 = pfVar8 + 1;
    *pfVar9 = fVar7 * *pfVar1 + *pfVar9;
    pfVar9 = pfVar9 + 1;
  } while (pfVar8 != (float *)(in_EAX + 0x4e4));
  return;
}


