// 00417950 FUN_00417950 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00417950(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  fVar2 = (float10)RwGetMaterialAmbient(param_1);
  fVar1 = (float)fVar2;
  if ((_DAT_004703c8 < fVar1) &&
     ((byte)(fVar1 < _DAT_004703cc |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN(_DAT_004703cc)) << 10) >> 8)) == 1)) {
    fVar2 = (float10)RwGetMaterialDiffuse(param_1);
    if ((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN((float10)DAT_004703d0)) << 10) >> 8) |
              (byte)((ushort)((ushort)(fVar2 == (float10)DAT_004703d0) << 0xe) >> 8)) == 0x40) {
      fVar2 = (float10)RwGetMaterialSpecular(param_1);
      if ((byte)((byte)((ushort)((ushort)(NAN(fVar2) || NAN((float10)DAT_004703d0)) << 10) >> 8) |
                (byte)((ushort)((ushort)(fVar2 == (float10)DAT_004703d0) << 0xe) >> 8)) == 0x40) {
        RwRemoveTextureModeFromMaterial(param_1,1);
        goto LAB_004179d7;
      }
    }
  }
  RwSetMaterialLightSampling(param_1,1);
  RwAddTextureModeToMaterial(param_1,1);
LAB_004179d7:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


