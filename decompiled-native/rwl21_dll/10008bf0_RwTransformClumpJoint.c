// 10008bf0 RwTransformClumpJoint [Global]
// programa: RWL21.DLL

uint __fastcall
RwTransformClumpJoint
          (undefined4 param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
                    /* 0x8bf0  510  RwTransformClumpJoint */
  if ((param_3 != 0) && (param_4 != 0)) {
    iVar1 = FUN_1001c500(param_5,param_2,(float *)(param_3 + 0x130),param_4,param_5);
    return (iVar1 == 0) - 1 & param_3;
  }
  FUN_1000cba0(1);
  return 0;
}


