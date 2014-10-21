#ifndef SIGWATCH_H
#define SIGWATCH_H

#include <QObject>
#include <signal.h>

class UnixSignalWatcherPrivate;


/*!
 * \brief The UnixSignalWatcher class converts Unix signals to Qt signals.
 *
 * To watch for a given signal, e.g. \c SIGINT, call \c watchForSignal(SIGINT)
 * and \c connect() your handler to unixSignal().
 */

class UnixSignalWatcher : public QObject
{
    Q_OBJECT
public:
    explicit UnixSignalWatcher(QObject *parent = 0);
    ~UnixSignalWatcher();

    void watchForSignal(int signal);

signals:
    void unixSignal(int signal);

private:
    UnixSignalWatcherPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(UnixSignalWatcher)
    Q_PRIVATE_SLOT(d_func(), void _q_onNotify(int))
};

#endif // SIGWATCH_H
