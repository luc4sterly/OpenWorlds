// 00411b30 FUN_00411b30 [Global]
// program: gamma.dll

int * __thiscall FUN_00411b30(void *this,int *param_1)

{
  undefined4 *this_00;
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  if (*(int *)this != *param_1) {
    piVar2 = *(int **)((int)this + 4);
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
      this_00 = *(undefined4 **)this;
      if (this_00 != (undefined4 *)0x0) {
        uVar1 = FUN_00405eb0((int)this_00);
        uVar4 = 0;
        if (uVar1 != 0) {
          do {
            piVar2 = (int *)FUN_00405e30(this_00,uVar4);
            puVar3 = (undefined4 *)*piVar2;
            if (puVar3 != (undefined4 *)0x0) {
              puVar3[1] = puVar3[1] + -1;
              if (puVar3[1] != 0) {
                puVar3 = (undefined4 *)0x0;
              }
              if (puVar3 != (undefined4 *)0x0) {
                (**(code **)*puVar3)(1);
              }
            }
            uVar4 = uVar4 + 1;
          } while (uVar4 < uVar1);
        }
        FUN_00404ed0(this_00 + 3);
        FUN_00411de0((int)this_00);
        FUN_0044e100(this_00);
      }
      FUN_0044e100(*(undefined4 **)((int)this + 4));
    }
    *(int *)this = *param_1;
    *(int *)((int)this + 4) = param_1[1];
    piVar2 = *(int **)((int)this + 4);
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
  }
  return this;
}


