// 0044df90 FUN_0044df90 [Global]
// program: gamma.dll

uint * __cdecl FUN_0044df90(uint *param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  ushort uVar2;
  
  uVar3 = param_2 & 0xff;
  puVar6 = param_1;
  if (0x10 < param_3) {
    uVar1 = (undefined1)param_2;
    uVar2 = CONCAT11(uVar1,uVar1);
    uVar3 = (uint)uVar2;
    if (4 < (int)param_3) {
      uVar3 = CONCAT22(uVar2,uVar2);
      uVar4 = -(int)param_1 & 3;
      uVar5 = param_3;
      if (uVar4 != 0) {
        uVar5 = param_3 - uVar4;
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(undefined1 *)puVar6 = uVar1;
          puVar6 = (uint *)((int)puVar6 + 1);
        }
      }
      param_3 = uVar5 & 3;
      uVar5 = uVar5 >> 2;
      if (uVar5 != 0) {
        for (; uVar5 != 0; uVar5 = uVar5 - 1) {
          *puVar6 = uVar3;
          puVar6 = puVar6 + 1;
        }
      }
    }
  }
  for (; param_3 != 0; param_3 = param_3 - 1) {
    *(char *)puVar6 = (char)uVar3;
    puVar6 = (uint *)((int)puVar6 + 1);
  }
  return param_1;
}


