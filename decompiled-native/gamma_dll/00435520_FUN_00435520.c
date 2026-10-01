// 00435520 FUN_00435520 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00435520(void *this,uint param_1,int param_2,int param_3,float param_4)

{
  float10 fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined1 local_18 [8];
  
  FUN_00427a20(local_18,param_1);
  uVar2 = FUN_00419950();
  uVar5 = uVar2;
  uVar3 = FUN_004196d0(param_3);
  FUN_00419420(uVar3,uVar5);
  fVar4 = FUN_00419700(uVar2,0,0);
  fVar1 = (float10)DAT_0047552c;
  FUN_004198f0();
  FUN_00433710(*(void **)this,local_18,param_2,param_3,
               _DAT_00475540 / (param_4 * (float)(fVar4 * fVar1)));
  return;
}


