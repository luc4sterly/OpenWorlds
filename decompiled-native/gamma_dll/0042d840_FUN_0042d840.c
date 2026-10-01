// 0042d840 FUN_0042d840 [Global]
// program: gamma.dll

void __thiscall FUN_0042d840(void *this,int *param_1)

{
  int iVar1;
  undefined ***pppuVar2;
  undefined4 uVar3;
  undefined4 extraout_EDX;
  undefined **local_5b8;
  undefined1 *local_5b4;
  undefined1 *local_5b0;
  undefined1 *local_5ac;
  undefined1 *local_5a8;
  undefined1 *local_590;
  undefined1 local_58c [264];
  undefined4 local_484 [4];
  undefined1 auStack_474 [8];
  undefined4 *local_46c;
  undefined1 auStack_468 [8];
  undefined4 *local_460;
  undefined1 auStack_45c [8];
  undefined4 *local_454;
  undefined1 auStack_450 [8];
  undefined4 *local_448;
  undefined **local_438;
  undefined1 local_434;
  undefined **local_334;
  undefined1 local_330;
  undefined **local_230;
  undefined1 local_22c;
  undefined **local_12c;
  undefined1 local_128;
  
  FUN_0042ca70(this);
  uVar3 = (**(code **)(*param_1 + 0x14))();
  *(undefined4 *)((int)this + 0xf0) = uVar3;
  local_5b4 = auStack_474;
  local_5ac = auStack_45c;
  local_5b0 = auStack_468;
  local_5a8 = auStack_450;
  local_5b8 = &PTR_LAB_00471ff8;
  while( true ) {
    local_590 = (undefined1 *)&local_5b8;
    iVar1 = *(int *)((int)this + 0xf0);
    if (iVar1 == -1) break;
    pppuVar2 = &local_5b8;
    if (iVar1 != 0x103) {
      FUN_0042c6a0(local_58c,param_1[3],iVar1);
      FUN_00451670();
      pppuVar2 = (undefined ***)local_590;
    }
    local_590 = (undefined1 *)pppuVar2;
    FUN_0042ba20(local_484);
    local_438 = local_5b8;
    local_434 = 0;
    FUN_0042e220(local_5b4,local_46c,(undefined4 *)0x3,(int)&local_438);
    local_334 = local_5b8;
    local_438 = local_5b8;
    local_330 = 0;
    FUN_0042e220(local_5b0,local_460,(undefined4 *)0x3,(int)&local_334);
    local_230 = local_5b8;
    local_334 = local_5b8;
    local_22c = 0;
    FUN_0042e220(local_5ac,local_454,(undefined4 *)0x1,(int)&local_230);
    local_12c = local_5b8;
    local_230 = local_5b8;
    local_128 = 0;
    FUN_0042e220(local_5a8,local_448,(undefined4 *)0x1,(int)&local_12c);
    local_12c = local_5b8;
    FUN_0042da80(this,extraout_EDX,param_1,local_484);
    FUN_0042e990(this,local_484);
    FUN_0042bc60((int)local_484);
    uVar3 = (**(code **)(*param_1 + 0x14))();
    *(undefined4 *)((int)this + 0xf0) = uVar3;
  }
  return;
}


