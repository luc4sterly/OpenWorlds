// 00425da0 Java_NET_worlds_scape_Transform_scale__FFF [Global]
// programa: gamma.dll

/* class _jobject * __stdcall Java_NET_worlds_scape_Transform_scale__FFF(struct JNIEnv_ *,class
   _jobject *,float,float,float) */

_jobject *
Java_NET_worlds_scape_Transform_scale__FFF
          (JNIEnv_ *param_1,_jobject *param_2,float param_3,float param_4,float param_5)

{
  undefined4 uVar1;
  float10 fVar2;
  
                    /* 0x25da0  9
                       ?Java_NET_worlds_scape_Transform_scale__FFF@@YGPAV_jobject@@PAUJNIEnv_@@PAV1@MMM@Z
                        */
  uVar1 = (**(code **)(*(int *)param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00418b10(uVar1,param_3,param_4,param_5);
  fVar2 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  (**(code **)(*(int *)param_1 + 0x1bc))(param_1,param_2,DAT_0049d250,param_3 * (float)fVar2);
  fVar2 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  (**(code **)(*(int *)param_1 + 0x1bc))(param_1,param_2,DAT_0049d254,param_4 * (float)fVar2);
  fVar2 = (float10)(**(code **)(*(int *)param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  (**(code **)(*(int *)param_1 + 0x1bc))(param_1,param_2,DAT_0049d258,param_5 * (float)fVar2);
  FUN_00412800((int *)param_1,param_2,DAT_0049d25c);
  return param_2;
}


