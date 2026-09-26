// 10033360 FUN_10033360 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10033360(float *param_1,int param_2,float *param_3,int param_4,char param_5)

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
  byte bVar11;
  float fVar12;
  undefined2 in_FPUControlWord;
  
  if (param_5 == '\x02') {
    fVar7 = *(float *)(param_4 + 0x74);
    DAT_10045028 = *(float *)(param_4 + 0x78);
    _DAT_10045030 = *(undefined4 *)(param_4 + 0x80);
    _DAT_10045034 = *(float *)(param_4 + 0x84);
    _DAT_10045038 = *(float *)(param_4 + 0x88);
    DAT_10045024 = fVar7;
    if (*(char *)(param_4 + 0x218) == '\x01') {
      _DAT_10045044 = CONCAT22(DAT_10045044_2,in_FPUControlWord);
      _DAT_10045020 = *(float *)(param_4 + 0x70);
      _DAT_10045048 = _DAT_10045044 & 0xfffffcff;
      _DAT_1004501c = *(float *)(param_4 + 0x6c);
      while (0 < param_2) {
        fVar10 = param_3[2];
        fVar1 = param_3[6];
        fVar12 = param_3[10];
        fVar2 = param_3[0xe];
        fVar3 = param_3[1];
        fVar4 = param_3[5];
        fVar5 = param_3[9];
        fVar6 = param_3[0xd];
        param_1[3] = param_1[1] * param_3[4] + param_3[0xc] +
                     param_1[2] * param_3[8] + *param_1 * *param_3;
        param_1[5] = param_1[1] * fVar1 + fVar2 + param_1[2] * fVar12 + *param_1 * fVar10;
        fVar1 = _DAT_1004502c;
        fVar10 = param_1[5];
        bVar11 = *(byte *)(param_1 + 0x12) & 0xc0;
        param_1[4] = param_1[1] * fVar4 + fVar6 + param_1[2] * fVar5 + *param_1 * fVar3;
        if ((int)fVar10 < (int)fVar7) {
          bVar11 = bVar11 | 0x10;
        }
        else {
          fVar1 = fVar1 / param_1[5];
          if ((int)DAT_10045028 < (int)fVar10) {
            bVar11 = bVar11 | 0x20;
          }
        }
        fVar12 = param_1[4];
        if ((int)fVar12 < 0) {
          bVar11 = bVar11 | 4;
        }
        if ((int)((uint)fVar12 & (uint)fVar10) < 0) {
          fVar10 = param_1[4];
          fVar12 = param_1[5];
        }
        if ((int)fVar10 < (int)fVar12) {
          bVar11 = bVar11 | 8;
        }
        fVar10 = param_1[5];
        fVar12 = param_1[3];
        if ((int)fVar12 < 0) {
          bVar11 = bVar11 | 1;
        }
        if ((int)((uint)fVar12 & (uint)fVar10) < 0) {
          fVar10 = param_1[3];
          fVar12 = param_1[5];
        }
        if ((int)fVar10 < (int)fVar12) {
          bVar11 = bVar11 | 2;
        }
        *(byte *)(param_1 + 0x12) = bVar11;
        if ((bVar11 & 0x3f) == 0) {
          param_1[8] = (float)(int)ROUND((_DAT_10045034 - param_1[5]) * fVar1 * _DAT_10045038);
          fVar10 = param_1[4] * fVar1 * _DAT_10045020;
          param_1[6] = (float)(int)ROUND(fVar1 * param_1[3] * _DAT_1004501c);
          param_1[7] = (float)(int)ROUND(fVar10);
          param_1[8] = (float)((int)param_1[8] + 0x1000000);
          param_1 = param_1 + 0x1d;
          param_2 = param_2 + -1;
        }
        else {
          param_1 = param_1 + 0x1d;
          param_2 = param_2 + -1;
          _DAT_1004504c = fVar1;
        }
      }
    }
    else {
      _DAT_10045020 = *(float *)(param_4 + 0x70);
      _DAT_1004501c = *(float *)(param_4 + 0x6c);
      while (0 < param_2) {
        fVar7 = param_1[1] * param_3[6] + param_3[0xe] +
                param_1[2] * param_3[10] + *param_1 * param_3[2];
        fVar10 = param_1[1] * param_3[4] + param_3[0xc] +
                 param_1[2] * param_3[8] + *param_1 * *param_3;
        fVar1 = param_1[1] * param_3[5] + param_3[0xd] +
                param_1[2] * param_3[9] + *param_1 * param_3[1];
        bVar11 = *(byte *)(param_1 + 0x12) & 0xc0;
        if (DAT_10045024 <= fVar7) {
          if (DAT_10045028 < fVar7) {
            bVar11 = bVar11 | 0x20;
          }
        }
        else {
          bVar11 = bVar11 | 0x10;
        }
        if (0.0 <= fVar1) {
          if (_DAT_1004502c < fVar1) {
            bVar11 = bVar11 | 8;
          }
        }
        else {
          bVar11 = bVar11 | 4;
        }
        if (0.0 <= fVar10) {
          if (_DAT_1004502c < fVar10) {
            bVar11 = bVar11 | 2;
          }
        }
        else {
          bVar11 = bVar11 | 1;
        }
        *(byte *)(param_1 + 0x12) = bVar11;
        if ((bVar11 & 0x3f) == 0) {
          param_1[3] = fVar10;
          fVar10 = fVar10 * _DAT_1004501c;
          param_1[5] = fVar7;
          param_1[4] = fVar1;
          param_1[8] = (float)(int)ROUND((_DAT_10045034 - fVar7) * _DAT_10045038);
          fVar1 = fVar1 * _DAT_10045020;
          param_1[8] = (float)((int)param_1[8] + 0x1000000);
          param_1[7] = (float)(int)ROUND(fVar1);
          param_1[6] = (float)(int)ROUND(fVar10);
          param_1 = param_1 + 0x1d;
          param_2 = param_2 + -1;
        }
        else {
          param_1[3] = fVar10;
          param_1[4] = fVar1;
          param_1[5] = fVar7;
          param_1 = param_1 + 0x1d;
          param_2 = param_2 + -1;
        }
      }
    }
  }
  else {
    _DAT_10045030 = *(undefined4 *)(param_4 + 0x80);
    _DAT_10045034 = *(float *)(param_4 + 0x84);
    _DAT_10045038 = *(float *)(param_4 + 0x88);
    if (*(char *)(param_4 + 0x218) == '\x01') {
      _DAT_10045044 = CONCAT22(DAT_10045044_2,in_FPUControlWord);
      _DAT_10045020 = *(float *)(param_4 + 0x70);
      _DAT_10045048 = _DAT_10045044 & 0xfffffcff;
      _DAT_1004501c = *(float *)(param_4 + 0x6c);
      while (0 < param_2) {
        fVar7 = *param_3;
        fVar6 = param_1[1] * param_3[6] + param_3[0xe] +
                param_1[2] * param_3[10] + *param_1 * param_3[2];
        fVar10 = param_3[4];
        fVar1 = param_3[8];
        fVar12 = param_3[0xc];
        fVar2 = param_3[1];
        fVar3 = param_3[5];
        fVar4 = param_3[9];
        fVar5 = param_3[0xd];
        fVar9 = _DAT_1004502c / fVar6;
        *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0x12) & 0xc0;
        fVar8 = _DAT_10045034 - fVar6;
        param_1[7] = (float)(int)ROUND((param_1[1] * fVar3 + fVar5 +
                                       param_1[2] * fVar4 + *param_1 * fVar2) * fVar9 *
                                       _DAT_10045020);
        fVar2 = fVar8 * fVar9 * _DAT_10045038;
        param_1[5] = fVar6;
        fVar7 = (param_1[1] * fVar10 + fVar12 + param_1[2] * fVar1 + *param_1 * fVar7) * fVar9 *
                _DAT_1004501c;
        param_1[8] = (float)(int)ROUND(fVar2);
        param_1[6] = (float)(int)ROUND(fVar7);
        param_1[8] = (float)((int)param_1[8] + 0x1000000);
        param_1 = param_1 + 0x1d;
        param_2 = param_2 + -1;
      }
    }
    else {
      _DAT_10045020 = *(float *)(param_4 + 0x70);
      _DAT_1004501c = *(float *)(param_4 + 0x6c);
      while (0 < param_2) {
        fVar2 = param_1[1] * param_3[6] + param_3[0xe] +
                param_1[2] * param_3[10] + *param_1 * param_3[2];
        fVar4 = param_1[1] * param_3[4] + param_3[0xc] +
                param_1[2] * param_3[8] + *param_1 * *param_3;
        fVar7 = param_3[1];
        fVar10 = param_3[5];
        fVar1 = param_3[9];
        fVar12 = param_3[0xd];
        param_1[3] = fVar4;
        fVar3 = _DAT_10045034 - fVar2;
        fVar7 = (param_1[2] * fVar1 + *param_1 * fVar7 + param_1[1] * fVar10 + fVar12) *
                _DAT_10045020;
        param_1[6] = (float)(int)ROUND(fVar4 * _DAT_1004501c);
        fVar3 = fVar3 * _DAT_10045038;
        param_1[7] = (float)(int)ROUND(fVar7);
        param_1[8] = (float)(int)ROUND(fVar3);
        param_1[5] = fVar2;
        *(byte *)(param_1 + 0x12) = *(byte *)(param_1 + 0x12) & 0xc0;
        param_1[8] = (float)((int)param_1[8] + 0x1000000);
        param_1 = param_1 + 0x1d;
        param_2 = param_2 + -1;
      }
    }
  }
  return;
}


