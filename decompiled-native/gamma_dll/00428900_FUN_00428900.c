// 00428900 FUN_00428900 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00428900(void *this,undefined4 *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  
  fVar13 = param_2 * param_2;
  fVar14 = _DAT_00473320 * param_2;
  fVar20 = _DAT_00473320 * fVar13;
  fVar1 = *(float *)((int)this + 0x30);
  fVar21 = _DAT_00473324 * fVar13;
  fVar2 = *(float *)((int)this + 0x38);
  fVar11 = _DAT_00473328 * param_2;
  fVar22 = _DAT_00473310 * fVar13;
  fVar19 = (fVar22 - fVar11) + _DAT_00473318;
  fVar3 = *(float *)((int)this + 0x34);
  fVar15 = _DAT_00473314 * param_2;
  fVar4 = *(float *)((int)this + 0x3c);
  fVar17 = _DAT_00473320 * fVar13 - fVar14;
  fVar5 = *(float *)((int)this + 0x1c);
  fVar23 = _DAT_00473324 * fVar13 + fVar14;
  fVar6 = *(float *)((int)this + 0x24);
  fVar13 = _DAT_00473310 * fVar13;
  fVar18 = (fVar13 - fVar11) + _DAT_00473318;
  fVar7 = *(float *)((int)this + 0x20);
  fVar8 = *(float *)((int)this + 0x28);
  fVar9 = *(float *)((int)this + 8);
  fVar10 = *(float *)((int)this + 0x10);
  fVar16 = (fVar13 - fVar11) + _DAT_00473318;
  fVar11 = *(float *)((int)this + 0xc);
  fVar12 = *(float *)((int)this + 0x14);
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = (fVar13 - fVar15) * fVar12 + fVar16 * fVar11 + fVar10 * fVar23 + fVar9 * fVar17;
  param_1[2] = (fVar13 - fVar15) * fVar8 + fVar18 * fVar7 + fVar6 * fVar23 + fVar5 * fVar17;
  param_1[3] = (fVar22 - fVar15) * fVar4 +
               fVar19 * fVar3 + (fVar21 + fVar14) * fVar2 + (fVar20 - fVar14) * fVar1;
  return;
}


