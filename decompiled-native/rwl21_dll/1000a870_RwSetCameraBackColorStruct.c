// 1000a870 RwSetCameraBackColorStruct [Global]
// program: RWL21.DLL

uint RwSetCameraBackColorStruct(uint param_1,uint *param_2)

{
  uint uVar1;
  
                    /* 0xa870  367  RwSetCameraBackColorStruct */
  if ((param_1 != 0) && (param_2 != (uint *)0x0)) {
    uVar1 = RwSetCameraBackColor(param_1,*param_2,param_2[1],param_2[2]);
    return uVar1;
  }
  FUN_1000cba0(1);
  return 0;
}


