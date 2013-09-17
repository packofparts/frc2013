#ifndef GYROROTATECOMMAND_H
#define GYROROTATECOMMAND_H

#include "../../../CommandBase.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class GyroRotateCommand: public CommandBase, public PIDOutput, public PIDSource
{
private:
	PIDController* pid;
	float headingGoal;
public:
	GyroRotateCommand();
	~GyroRotateCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();

	void SetParams(double headingDiff, double timeout);

	/**
	 * PIDOuptut implementation
	 */
	void PIDWrite(float output);
	virtual double PIDGet();
};

#endif
