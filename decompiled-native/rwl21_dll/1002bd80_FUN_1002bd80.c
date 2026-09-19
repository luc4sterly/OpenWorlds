// 1002bd80 FUN_1002bd80 [Global]
// programa: RWL21.DLL

uint FUN_1002bd80(uint param_1)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)0x0;
  if (param_1 != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0x14);
  }
  puVar2 = (uint *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    puVar2 = (uint *)puVar4[5];
  }
  uVar3 = puVar4[0x18];
  if (param_1 == uVar3) {
    uVar3 = puVar4[0x19];
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(uint **)(uVar3 + 0x14) = puVar2;
  puVar4[5] = 0;
  if (puVar2 == (uint *)0x0) {
    *(uint *)(*(int *)(param_1 + 0x18) + 4) = uVar3;
  }
  else if (((*puVar2 & 4) == 0) || ((undefined4 *)puVar2[4] != puVar4)) {
    if (puVar2[0x11] == 3) {
      if ((undefined4 *)puVar2[0x18] == puVar4) {
        puVar2[0x18] = uVar3;
      }
      else {
        puVar2[0x19] = uVar3;
      }
    }
  }
  else {
    puVar2[4] = uVar3;
  }
  iVar1 = puVar4[0x11];
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(puVar4[0x13]);
      puVar4[0x13] = 0;
      puVar4[0x12] = 0;
    }
    else if (iVar1 != 3) {
      FUN_1000cba0(0x65);
    }
  }
  puVar4[0x11] = 0;
  FUN_10037010(DAT_1005adac,puVar4);
  return param_1;
}


