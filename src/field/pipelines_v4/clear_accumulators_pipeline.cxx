#include <field_pipelines.h>
#include <v4.h>

using namespace v4;

void
clear_accumulators_pipeline( clear_accumulators_pipeline_args_t * args,
                             int pipeline_rank ) {
  // Have each pipeline clear its personal accumulator 
  // Any compiler worth its salt has highly optimized versions of memset
  memset( args->a + (pipeline_rank+1)*args->n_voxel, 0,
          args->n_voxel*sizeof(accumulator_t) );
}

