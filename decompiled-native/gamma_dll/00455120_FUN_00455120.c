// 00455120 FUN_00455120 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_00455120(byte param_1,char *param_2,ushort *param_3)

{
  byte bVar1;
  uint uVar2;
  
  *param_3 = *param_3 & 0xfc7f | 0x80;
  *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) & 0xf3;
  *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) & 0xef;
  uVar2 = (uint)*param_2;
  if (uVar2 == 0x61) {
    bVar1 = 1;
  }
  else if (uVar2 == 0x72) {
    bVar1 = 0;
  }
  else {
    if (uVar2 != 0x77) {
      return 0;
    }
    bVar1 = 2;
  }
  *(byte *)param_3 = (byte)*param_3 & 0xfc | bVar1;
  if (param_2[1] == '+') {
    uVar2 = uVar2 << 8 | 0x2b;
    if (param_2[2] == 'b') {
      *(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) & 0xef | 0x10;
    }
  }
  else if ((param_2[1] == 'b') &&
          (*(byte *)((int)param_3 + 1) = *(byte *)((int)param_3 + 1) & 0xef | 0x10,
          param_2[2] == '+')) {
    uVar2 = uVar2 << 8 | 0x2b;
  }
  if (uVar2 == 0x61) {
    param_1 = 6;
  }
  else if (uVar2 == 0x72) {
    param_1 = 1;
  }
  else if (uVar2 == 0x77) {
    param_1 = 2;
  }
  else if (uVar2 == 0x612b) {
    param_1 = 7;
  }
  else if (uVar2 == 0x722b) {
    param_1 = 3;
  }
  else if (uVar2 == 0x772b) {
    param_1 = 3;
  }
  *(byte *)param_3 = (byte)*param_3 & 0xe3 | (param_1 & 7) << 2;
  return 1;
}


