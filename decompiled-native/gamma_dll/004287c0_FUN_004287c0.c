// 004287c0 FUN_004287c0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_004287c0(void *this,undefined4 *param_1,float param_2)

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
  float fVar24;
  float fVar25;
  
  fVar13 = param_2 * param_2;
  fVar14 = fVar13 * param_2;
  fVar15 = _DAT_00473310 * fVar13;
  fVar24 = (_DAT_00473314 * fVar14 - fVar15) + _DAT_00473318;
  fVar1 = *(float *)((int)this + 0x30);
  fVar25 = _DAT_0047331c * fVar14;
  fVar2 = *(float *)((int)this + 0x38);
  fVar16 = _DAT_00473314 * fVar13;
  fVar3 = *(float *)((int)this + 0x34);
  fVar4 = *(float *)((int)this + 0x3c);
  fVar17 = fVar13 * param_2;
  fVar18 = _DAT_00473310 * fVar13;
  fVar22 = (_DAT_00473314 * fVar17 - fVar18) + _DAT_00473318;
  fVar5 = *(float *)((int)this + 0x1c);
  fVar23 = _DAT_0047331c * fVar17;
  fVar6 = *(float *)((int)this + 0x24);
  fVar19 = _DAT_00473314 * fVar13;
  fVar7 = *(float *)((int)this + 0x20);
  fVar8 = *(float *)((int)this + 0x28);
  fVar20 = (_DAT_00473314 * fVar17 - fVar18) + _DAT_00473318;
  fVar9 = *(float *)((int)this + 8);
  fVar21 = _DAT_0047331c * fVar17;
  fVar10 = *(float *)((int)this + 0x10);
  fVar11 = *(float *)((int)this + 0xc);
  fVar12 = *(float *)((int)this + 0x14);
  *param_1 = &PTR_LAB_00473390;
  param_1[1] = (fVar17 - fVar13) * fVar12 +
               ((fVar17 - fVar19) + param_2) * fVar11 + (fVar21 + fVar18) * fVar10 + fVar20 * fVar9;
  param_1[2] = (fVar17 - fVar13) * fVar8 +
               ((fVar17 - fVar19) + param_2) * fVar7 + (fVar23 + fVar18) * fVar6 + fVar22 * fVar5;
  param_1[3] = (fVar14 - fVar13) * fVar4 +
               ((fVar14 - fVar16) + param_2) * fVar3 + (fVar25 + fVar15) * fVar2 + fVar24 * fVar1;
  return param_1;
}


