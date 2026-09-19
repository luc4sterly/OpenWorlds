// 10012ab0 RwDisc [Global]
// programa: RWL21.DLL

undefined4 __fastcall RwDisc(undefined4 param_1,int param_2,float param_3,float param_4,int param_5)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  
                    /* 0x12ab0  71  RwDisc */
  uVar3 = 0;
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  iVar1 = FUN_1001d760(*(int *)(DAT_1005dfcc + 0x1c),param_2);
  if (iVar1 != 0) {
    iVar1 = 2;
    fVar5 = 0.0;
    fVar4 = 0.0;
    pfVar2 = (float *)FUN_1001d770();
    FUN_1001c820(pfVar2,fVar4,param_3,fVar5,iVar1);
    uVar3 = RwCone(0.0,param_4,param_5);
    FUN_1001d780();
  }
  return uVar3;
}


