-- onFrame
function onFrame(frame,length)
    sampleBytes = length-ScopeFun.SCOPEFUN_FRAME_HEADER;
	start = ScopeFun.SCOPEFUN_FRAME_HEADER
	for i=start,start+sampleBytes,1 do
		frame.data[i] = math.abs( math.tan( i ) )
	end
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
  return hw
end

-- onInit
function onInit(ctx)
  return ctx
end

