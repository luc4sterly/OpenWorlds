// 00451910 FUN_00451910 [Global]
// programa: gamma.dll

ushort * FUN_00451910(byte param_1,ushort *param_2,ushort *param_3)

{
  undefined4 uVar1;
  
  while ((param_2 < param_3 && (uVar1 = FUN_00451aa0(*param_2), ((byte)uVar1 & param_1) == 0))) {
    param_2 = param_2 + 1;
  }
  return param_2;
}


