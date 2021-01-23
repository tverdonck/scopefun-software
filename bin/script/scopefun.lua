-- onFrame
function onFrame(data,length)
	return data,length
end

-- onSample
function onSample(sample,ch0,ch1,fun,dig)
    return sample,ch0,ch1,fun,dig
end

-- onDisplay
function onDisplay(data)
	return data
end

-- onConfigure
function onConfigure(hw)
  print( ScopeFun.sfGetYGainA(hw) )
  print( "\n" )
  return hw
end

-- onInit
function onInit(ctx)
  hw = ScopeFun.sfCreateSHardware()
  ScopeFun.sfSetDefault(hw)
  ScopeFun.sfHardwareConfig(ctx,hw)
  return ctx
end

-- onFunction
function onFunction(ch0,ch1)
	func = ch0+ch1
    return func
end

-- onUpload
function onUpload(gen)
	for i=0,32767,1 do
		gen.analog0[i] = 0
		gen.analog1[i] = 0
        bits = 0
		for j=0,11,1 do
			bits = bits | ((i%2)<<j)
		end
		gen.digital[i] = bits
	end
    return gen, 32768
end

