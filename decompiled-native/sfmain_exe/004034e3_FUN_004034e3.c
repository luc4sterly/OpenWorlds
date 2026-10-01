// 004034e3 FUN_004034e3 [Global]
// program: sfmain.exe

void __fastcall FUN_004034e3(undefined4 param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(in_EAX + -10);
  puVar1 = param_2 + 0x28;
  do {
    iVar3 = (*(int *)((int)piVar2 + 0x12) >> 0x10) * -0x86 +
            (piVar2[3] >> 0x10) * 0x806 +
            (*(int *)((int)piVar2 + 10) >> 0x10) * 0x166d +
            (*(int *)((int)piVar2 + 6) >> 0x10) * 0x166d +
            (piVar2[1] >> 0x10) * 0x806 + (*piVar2 >> 0x10) * -0x176 + (short)*piVar2 * -0x86 +
            (piVar2[2] >> 0x10) * 0x2000 + (piVar2[4] >> 0x10) * -0x176 + 0x1000 >> 0xd;
    if (iVar3 < -0x8000) {
      iVar3 = -0x8000;
    }
    else if (0x7fff < iVar3) {
      iVar3 = 0x7fff;
    }
    *param_2 = (short)iVar3;
    param_2 = param_2 + 1;
    piVar2 = (int *)((int)piVar2 + 2);
  } while (param_2 != puVar1);
  return;
}


