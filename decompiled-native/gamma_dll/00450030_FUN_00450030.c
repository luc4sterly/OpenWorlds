// 00450030 FUN_00450030 [Global]
// program: gamma.dll

uint __thiscall FUN_00450030(void *this,char param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  puVar2 = *(undefined4 **)((int)this + 0x24);
  iVar4 = FUN_004553d0((int)puVar2,-1);
  if (iVar4 < 0) {
    piVar1 = puVar2 + 0xb;
    iVar4 = *piVar1;
    *piVar1 = *piVar1 + -1;
    if (iVar4 == 0) {
      uVar5 = FUN_00455440(puVar2);
    }
    else {
      pbVar3 = (byte *)puVar2[10];
      puVar2[10] = puVar2[10] + 1;
      uVar5 = (uint)*pbVar3;
    }
  }
  else {
    uVar5 = 0xffffffff;
  }
  if (uVar5 == 0xffffffff) {
    return 0xffffffff;
  }
  if (param_1 != '\0') {
    uVar6 = FUN_004555b0(uVar5,*(int *)((int)this + 0x24));
    if (uVar6 == 0xffffffff) {
      return 0xffffffff;
    }
  }
  return uVar5;
}


